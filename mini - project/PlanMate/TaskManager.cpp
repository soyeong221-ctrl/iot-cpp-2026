#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

void TaskManager::printSimpleTasks() {
	for (int i = 0; i < tasks.size(); i++) {
		std::cout << i + 1 << ". ";

		if (tasks[i].type == 0) {
			std::cout << "[일정] ";
		}
		else {
			std::cout << (tasks[i].isDone ? "[DONE] " : "[TO-DO] ");
		}

		std::cout << tasks[i].title;
		std::cout << " (" << tasks[i].date << ")";

		if (tasks[i].type == 1) {
			std::cout << " / 우선순위: " << tasks[i].priority;
		}

		std::cout << std::endl;
	}
}

void TaskManager::load() {
	std::ifstream file("tasks.txt");
	if (!file) return;

	Task t;

	tasks.clear();	// 실행시 중복 로딩 방지

	while (file >> t.title >> t.date >> t.priority >> t.isDone >> t.type) {
		tasks.push_back(t);
	}
}

void TaskManager::save() {
	std::ofstream file("tasks.txt");

	for (int i = 0; i < tasks.size(); i++) {
		file << tasks[i].title << " "
			<< tasks[i].date << " "
			<< tasks[i].priority << " "
			<< tasks[i].isDone << " "
			<< tasks[i].type << std::endl;
	}
}

void TaskManager::sortByDate() {
	std::sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
		return a.date < b.date;
		});

	std::cout << "날짜순 정렬 완료!" << std::endl;
}

// 1번: 전체 일정 보기
void TaskManager::showAllTasks() {
	if (tasks.empty()) {
		std::cout << "일정이 없습니다." << std::endl;
		return;
	}

	sortByDate();

	printSimpleTasks();
}

// 2번: 날짜별 일정 보기
void TaskManager::showTasksByDate() {
	std::string targetDate;
	std::cout << "조회할 날짜 입력: ";
	std::getline(std::cin, targetDate);

	bool found = false;

	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == targetDate) {
			std::cout << i + 1 << ". " << tasks[i].title << std::endl;
			found = true;
		}
	}

	if (!found) {
		std::cout << "해당 날짜에 일정이 없습니다." << std::endl;
	}
}


// 3번: 일정 추가
void TaskManager::addTask() {

	Task t;
	std::string input;

	// 타입 선택
	std::cout << "[1.일정] [2.할일]: ";
	std::getline(std::cin, input);
	int typeChoice = std::stoi(input);

	t.type = (typeChoice == 1) ? 0 : 1;

	// 내용
	std::cout << "내용 입력: ";
	std::getline(std::cin, t.title);

	// 날짜
	std::cout << "날짜 입력 (YYYY-MM-DD): ";
	std::getline(std::cin, t.date);

	// 우선순위
	std::cout << "우선순위 (1~3): ";
	std::getline(std::cin, input);
	t.priority = std::stoi(input);

	t.isDone = false;

	tasks.push_back(t);
	save();

	std::cout << "일정 추가 완료!" << std::endl;
}

// 4번: 일정 삭제
void TaskManager::deleteTask() {
	if (tasks.empty()) {
		std::cout << "삭제할 일정이 없습니다." << std::endl;
		return;
	}

	printSimpleTasks();

	std::string input;
	std::getline(std::cin, input);
	int num = std::stoi(input);

	int index = num - 1;

	if (index < 0 || index >= tasks.size()) {
		std::cout << "잘못된 번호입니다." << std::endl;
	}
	else {
		tasks.erase(tasks.begin() + index);
		save();
		std::cout << "삭제 완료!" << std::endl;
	}
}

// 5번: 일정 수정
void TaskManager::editTask() {
	if (tasks.empty()) {
		std::cout << "수정할 일정이 없습니다." << std::endl;
		return;
	}

	printSimpleTasks();

	std::string input;

	std::cout << "수정할 번호: ";
	std::getline(std::cin, input);
	int index = std::stoi(input) - 1;

	if (index < 0 || index >= tasks.size()) {
		std::cout << "잘못된 번호입니다." << std::endl;
		return;
	}

	std::cout << "새 내용: ";
	std::getline(std::cin, tasks[index].title);

	std::cout << "새 날짜 (YYYY-MM-DD): ";
	std::getline(std::cin, tasks[index].date);

	std::cout << "새 우선순위: ";
	std::getline(std::cin, input);
	tasks[index].priority = std::stoi(input);

	save();

	std::cout << "수정 완료!" << std::endl;
}

// 6번: 완료 [TO-DO] → [DONE]
void TaskManager::toggleDone() {
	if (tasks.empty()) {
		std::cout << "할 일이 없습니다." << std::endl;
		return;
	}

	printSimpleTasks();

	std::string input;

	std::cout << "완료 처리할 번호: ";
	std::getline(std::cin, input);
	int index = std::stoi(input) - 1;

	if (index < 0 || index >= tasks.size()) {
		std::cout << "잘못된 번호입니다." << std::endl;
		return;
	}

	tasks[index].isDone = !tasks[index].isDone;

	save();

	std::cout << "상태 변경 완료!" << std::endl;
}