#include <iostream>
#include "TaskManager.hpp"

int main() {
    TaskManager manager("data/tasks.txt");
    int choice;
    std::string desc;

    do {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. List tasks\n";
        std::cout << "2. Add task\n";
        std::cout << "3. Complete task\n";
        std::cout << "4. Delete task\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch(choice) {
            case 1:
                manager.listTasks();
                break;
            case 2:
                std::cout << "Task description: ";
                std::getline(std::cin, desc);
                manager.addTask(desc);
                break;
            case 3:
                int idComplete;
                std::cout << "Task ID to complete: ";
                std::cin >> idComplete;
                manager.completeTask(idComplete);
                break;
            case 4:
                int idDelete;
                std::cout << "Task ID to delete: ";
                std::cin >> idDelete;
                manager.deleteTask(idDelete);
                break;
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}