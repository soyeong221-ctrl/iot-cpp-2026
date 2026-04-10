#pragma once
#include <vector>
#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void load();
    void save();
    void printSimpleTasks();
    void sortByDate();

    void showAllTasks();
    void showTasksByDate();
    void addTask();
    void deleteTask();
    void editTask();
    void toggleDone();
};