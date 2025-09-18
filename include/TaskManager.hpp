#pragma once
#include <vector>
#include <string>
#include "Task.hpp"

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId;
    std::string dataFile;

public:
    TaskManager(const std::string& file);
    void addTask(const std::string& description);
    void listTasks() const;
    void completeTask(int id);
    void deleteTask(int id);
    void loadFromFile();
    void saveToFile() const;
};