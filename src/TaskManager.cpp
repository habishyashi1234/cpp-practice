#include "TaskManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

TaskManager::TaskManager(const std::string& file) : nextId(1), dataFile(file) {
    loadFromFile();
}

void TaskManager::addTask(const std::string& description) {
    tasks.emplace_back(nextId++, description);
    saveToFile();
}

void TaskManager::listTasks() const {
    for (const auto& task : tasks) {
        std::cout << "[" << (task.isCompleted() ? "X" : " ") << "] "
                  << task.getId() << ": " << task.getDescription() << std::endl;
    }
}

void TaskManager::completeTask(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markComplete();
            saveToFile();
            return;
        }
    }
    std::cout << "Task not found!\n";
}

void TaskManager::deleteTask(int id) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [id](const Task& t){ return t.getId() == id; }), tasks.end());
    saveToFile();
}

void TaskManager::loadFromFile() {
    std::ifstream inFile(dataFile);
    if (!inFile.is_open()) return;
    
    tasks.clear();
    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        int id;
        bool completed;
        std::string desc;
        iss >> id >> completed;
        getline(iss, desc);
        if (!desc.empty() && desc[0] == ' ') desc.erase(0, 1); // remove leading space
        tasks.emplace_back(id, desc, completed);
        nextId = std::max(nextId, id + 1);
    }
}

void TaskManager::saveToFile() const {
    std::ofstream outFile(dataFile);
    for (const auto& task : tasks) {
        outFile << task.getId() << " " << task.isCompleted() << " " << task.getDescription() << "\n";
    }
}