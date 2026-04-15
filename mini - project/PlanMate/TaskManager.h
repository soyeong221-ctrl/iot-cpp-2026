// 설계도

#pragma once
#include <vector>
#include "Task.h"

class TaskManager {
private:
    // 데이터
    std::vector<Task> tasks;
    std::string selectedDate;

public:
    // 1. 파일 관리
    void load();
    void save();

    // 2. 출력
    void printSimpleTasks();
    void showAllTasks();
    void showTasksByDate();
    void showTasksByDateInternal(std::string targetDate);

    // 3. 데이터 처리
    void sortByDate();
    bool hasTaskOnDate(std::string date);
    bool hasTodoOnDate(std::string date);

    // 4. 사용자 액션
    void addTask();
    void deleteTask();
    void editTask();
    void toggleDone();
    
    // 5. UI(컨트롤)
    void showCalendar();
    void showDateDetail();
    void calendarLoop();
    void showTodayTodo();
};

int safeInputInt(const std::string& prompt, int defaultValue = -1);