#include "Task.hpp"

Task::Task(int id, const std::string& desc, bool completed)
    : id(id), description(desc), completed(completed) {}

int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }
bool Task::isCompleted() const { return completed; }
void Task::markComplete() { completed = true; }