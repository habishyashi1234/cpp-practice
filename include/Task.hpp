#pragma once
#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task(int id, const std::string& desc, bool completed = false);
    int getId() const; // to retreive the unique id of the task.
    std::string getDescription() const; // to get the description of the task(therefore must be a constant).
    bool isCompleted() const; // flag to determine whether and when the task gets completed.
    void markComplete(); // used to retreive the completed tasks.
};