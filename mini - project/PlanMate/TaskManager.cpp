#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <sstream>


std::string centerAlign(const std::string& text, int width) {
	int padding = width - (int)text.length();

	if (padding <= 0) return text;

	int left = padding / 2;
	int right = padding - left;

	return std::string(left, ' ') + text + std::string(right, ' ');
}

int getDaysInMonth(int year, int month);

// 날짜 입력 검증
bool isValidDate(const std::string& date) {

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	try {
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (month < 1 || month > 12)
			return false;

		int maxDay = getDaysInMonth(year, month);

		if (day < 1 || day > maxDay)
			return false;

		return true;
	}
	catch (...) {
		return false;
	}
}

void pauseScreen() {

	std::cout << "\nEnter 누르면 계속..♥";
	std::cin.get();
}

// 입력 헬퍼 함수
int safeInputInt(const std::string& prompt, int defaultValue) {
	std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);

	if (input.empty()) {
		return defaultValue;
	}

	try {
		return std::stoi(input);
	}
	catch (...) {
		std::cout << "❌ 숫자만 입력하세요!\n";
		return defaultValue;
	}
}

// 오늘 날짜 자동
std::string getToday() {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);	// 시간을 구조체로 변환

	int year = 1900 + ltm.tm_year;
	int month = 1 + ltm.tm_mon;
	int day = ltm.tm_mday;

	char buffer[11];
	sprintf_s(buffer, "%04d-%02d-%02d", year, month, day);

	return std::string(buffer);
}

int getDaysInMonth(int year, int month) {

	// 1. 31일인 달
	if (month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12)
		return 31;

	// 2. 30일인 달
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;

	// 3. 2월 (윤년 계산)
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return 29;
		else
			return 28;
	}

	return 30; // 안전용
}

int getStartDay(int year, int month) {
	tm timeInfo = {};

	timeInfo.tm_year = year - 1900; // tm은 1900 기준
	timeInfo.tm_mon = month - 1;    // 0부터 시작 (0=1월)
	timeInfo.tm_mday = 1;           // 1일

	mktime(&timeInfo); // 시간 계산

	return timeInfo.tm_wday; // 요일 반환 (0~6)
}

//파일 관련
void TaskManager::load() {
	std::ifstream file("tasks.txt");
	if (!file) return;

	Task t;

	tasks.clear();	// 실행시 중복 로딩 방지

	selectedDate = getToday();

	std::string line;

	while (std::getline(file, line)) {

		std::stringstream ss(line);
		std::string temp;

		std::getline(ss, t.title, '|');
		std::getline(ss, t.date, '|');
		std::getline(ss, t.time, '|');

		std::getline(ss, temp, '|');
		try {
			t.priority = std::stoi(temp);
		}
		catch (...) {
			t.priority = 0;
		}

		std::getline(ss, temp, '|');
		try {
			t.isDone = std::stoi(temp);
		}
		catch (...) {
			t.isDone = 0;
		}

		std::getline(ss, temp, '|');
		try {
			t.type = std::stoi(temp);
		}
		catch (...) {
			t.type = 0;
		}

		tasks.push_back(t);
	}

}

void TaskManager::save() {
	std::ofstream file("tasks.txt");

	for (int i = 0; i < tasks.size(); i++) {
		file << tasks[i].title << "|"
			<< tasks[i].date << "|"
			<< tasks[i].time << "|"
			<< tasks[i].priority << "|"
			<< tasks[i].isDone << "|"
			<< tasks[i].type << std::endl;
	}
}

// 데이터 처리
void TaskManager::sortByDate() {
	std::sort(tasks.begin(), tasks.end(), [](Task a, Task b) {

		// 1. 날짜
		if (a.date != b.date)
			return a.date < b.date;

		// 2. 타입(일정 먼저)
		if (a.type != b.type)
			return a.type < b.type;	// 0(일정) -> 1(할일)

		// 3. 우선순위(숫자 1이 먼저)
		return a.priority < b.priority;

		});
}

bool TaskManager::hasTaskOnDate(std::string date) {
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == date)
			return true;
	}
	return false;
}

bool TaskManager::hasTodoOnDate(std::string date) {
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == date && tasks[i].type == 1 && !tasks[i].isDone) {
			return true;
		}
	}
	return false;
}

void TaskManager::showTasksByDateInternal(std::string targetDate) {
	bool found = false;

	std::cout << "\n[일정]\n";
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].type == 0 && tasks[i].date == targetDate) {
			std::cout << "- " << tasks[i].time << " " << tasks[i].title << std::endl;
			found = true;
		}
	}

	std::cout << "\n[할일]\n";
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].type == 1 && tasks[i].date == targetDate) {
			std::cout << "- " << tasks[i].title;

			if (tasks[i].isDone)
				std::cout << " [DONE]";

			std::cout << std::endl;
			found = true;
		}
	}

	if (!found) {
		std::cout << "일정 없음\n";
	}
}

// 1번: 전체 일정 보기
void TaskManager::showAllTasks() {
	if (tasks.empty()) {
		std::cout << "일정이 없습니다." << std::endl;
		return;
	}

	sortByDate();	// 1. 정렬

	std::string currentDate = "";	// 2. 현재 날짜 기억

	for (int i = 0; i < tasks.size(); i++) {

		// 3. 날짜 바뀌었을 때만 실행
		if (tasks[i].date != currentDate) {
			currentDate = tasks[i].date;
			std::cout << "\n=== " << currentDate << " ===" << std::endl;

			// 4. 일정 출력
			std::cout << "\n[일정]" << std::endl;

			for (int j = 0; j < tasks.size(); j++) {
				if (tasks[j].date == currentDate && tasks[j].type == 0) {
					std::cout << "- " << tasks[j].time << " " << tasks[j].title << std::endl;
				}
			}

			// 5. 할일 출력
			std::cout << "\n[할일]" << std::endl;

			for (int j = 0; j < tasks.size(); j++) {
				if (tasks[j].date == currentDate && tasks[j].type == 1) {
					std::cout << "- " << tasks[j].title << " (우선순위: " << tasks[j].priority << ")";

					if (tasks[j].isDone) {
						std::cout << " [DONE]";
					}
					std::cout << std::endl;
				}
			}
		}
	}
}


// 사용자 액션
// 3번: 일정 추가
void TaskManager::addTask() {

	Task t;

	int typeChoice = safeInputInt("[1.일정] [2.할일]: ");

	if (typeChoice != 1 && typeChoice != 2) {
		std::cout << "잘못된 입력입니다.\n";
		return;
	}

	t.type = (typeChoice == 1) ? 0 : 1;

	std::cout << "내용 입력: ";
	std::getline(std::cin, t.title);

	if (t.title.empty()) {
		std::cout << "내용은 필수입니다.\n";
		return;
	}

	t.date = selectedDate;

	if (t.type == 0) {
		std::cout << "시간 입력 (00:00): ";
		std::getline(std::cin, t.time);

		if (t.time.empty()) {
			std::cout << "시간은 필수입니다.\n";
			return;
		}
	}
	else {
		t.priority = safeInputInt("우선순위 1=★★★ 2=★★ 3=★ : ");

		if (t.priority < 1 || t.priority > 3) {
			std::cout << "우선순위는 1=★★★ 2=★★ 3=★ 입니다.\n";
			return;
		}
	}

	t.isDone = false;

	tasks.push_back(t);
	save();

	std::cout << "일정 추가 완료!\n";
	pauseScreen();
}


// 4번: 일정 삭제
void TaskManager::deleteTask() {
	std::vector<int> indexList;

	std::cout << "\n==== " << selectedDate << " ====\n";

	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == selectedDate) {

			indexList.push_back(i);

			std::cout << indexList.size() << ". ";

			if (tasks[i].type == 0) {
				std::cout << "[일정] " << tasks[i].time << " " << tasks[i].title;
			}
			else {
				std::cout << "[할일] " << tasks[i].title;
			}

			std::cout << "\n";
		}
	}

	if (indexList.empty()) {
		std::cout << "삭제할 일정이 없습니다.\n";
		pauseScreen();
		return;
	}

	int index = safeInputInt("삭제할 번호: ") - 1;

	if (index < 0 || index >= indexList.size()) {
		std::cout << "잘못된 번호입니다.\n";
		return;
	}

	int realIndex = indexList[index];

	tasks.erase(tasks.begin() + realIndex);
	save();

	std::cout << "삭제 완료!\n";
	pauseScreen();
}

// 5번: 일정 수정
void TaskManager::editTask() {
	if (tasks.empty()) {
		std::cout << "수정할 일정이 없습니다.\n";
		pauseScreen();
		return;
	}

	std::vector<int> indexList;
	std::string input;

	std::cout << "\n==== " << selectedDate << " ====\n";

	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == selectedDate) {

			indexList.push_back(i);

			std::cout << indexList.size() << ". ";

			if (tasks[i].type == 0) {
				std::cout << "[일정] " << tasks[i].time << " " << tasks[i].title;
			}
			else {
				std::cout << "[할일] " << tasks[i].title;
			}

			std::cout << "\n";
		}
	}

	if (indexList.empty()) {
		std::cout << "수정할 일정이 없습니다.\n";
		return;
	}

	// =========================
	// 1. 수정할 번호 (안전 입력)
	// =========================
	int index = safeInputInt("수정할 번호: ") - 1;

	if (index < 0 || index >= indexList.size()) {
		std::cout << "잘못된 번호입니다.\n";
		pauseScreen();
		return;
	}

	int realIndex = indexList[index];

	// =========================
	// 2. 제목 (Enter 유지)
	// =========================
	std::cout << "새 내용 (Enter = 유지): ";
	std::getline(std::cin, input);
	if (!input.empty()) {
		tasks[realIndex].title = input;
	}

	// =========================
	// 3. 날짜 (Enter 유지)
	// =========================
	std::cout << "새 날짜 YYYY-MM-DD (Enter = 유지): ";
	std::getline(std::cin, input);

	if (!input.empty()) {

		if (isValidDate(input)) {
			tasks[realIndex].date = input;
		}
		else {
			std::cout << "❌ 잘못된 날짜입니다. 수정되지 않았습니다.\n";
		}
	}

	// =========================
// 4. 우선순위 (할일만)
// =========================
	if (tasks[realIndex].type == 1) {

		std::cout << "새 우선순위 1=★★★ 2=★★ 3=★ (Enter = 유지): ";
		std::getline(std::cin, input);

		if (!input.empty()) {
			try {
				int p = std::stoi(input);
				if (p >= 1 && p <= 3) {
					tasks[realIndex].priority = p;
				}
				else {
					std::cout << "우선순위는 1~3 입니다.\n";
				}
			}
			catch (...) {
				std::cout << "숫자만 입력하세요.\n";
			}
		}
	}

	save();

	std::cout << "수정 완료!\n";
	pauseScreen();
}


// 6번: 완료 [TO-DO] → [DONE]
void TaskManager::toggleDone() {

	std::string today = getToday();
	std::vector<int> indexList;

	// =========================
	// 1. 오늘 할일만 출력
	// =========================
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].type == 1 && tasks[i].date == today) {

			indexList.push_back(i);

			std::cout << indexList.size() << ". "
				<< tasks[i].title;

			if (tasks[i].isDone)
				std::cout << " [DONE]";

			std::cout << std::endl;
		}
	}

	if (indexList.empty()) {
		std::cout << "오늘 할 일이 없습니다.\n";
		pauseScreen();
		return;
	}

	// =========================
	// 2. 입력
	// =========================
	std::cout << "\n-----------------------------------------\n";

	int index = safeInputInt("\n완료 처리할 번호: ") - 1;

	if (index < 0 || index >= indexList.size()) {
		std::cout << "잘못된 번호입니다.\n";
		pauseScreen();
		return;
	}

	// =========================
	// 3. 상태 변경
	// =========================
	int realIndex = indexList[index];
	tasks[realIndex].isDone = !tasks[realIndex].isDone;

	save();

	std::cout << "상태 변경 완료!\n";
	pauseScreen();
}

const int BOX_WIDTH = 44;

// UI 컨트롤

void TaskManager::showCalendar() {

	system("cls");

	if (!isValidDate(selectedDate)) {
		selectedDate = getToday();
	}

	int year = std::stoi(selectedDate.substr(0, 4));
	int month = std::stoi(selectedDate.substr(5, 2));

	int daysInMonth = getDaysInMonth(year, month);
	int startDay = getStartDay(year, month);

	std::string today = getToday();

	// =========================
	// 🔷 TOP BOX📅
	// =========================
	std::cout << "┌────────────────────────────────────────────┐\n";
	std::cout << "│            📅 PlanMate Calendar            │\n";
	std::cout << "├────────────────────────────────────────────┤\n";

	std::string todayStr = "Today: " + today;
	std::cout << "│" << centerAlign(todayStr, BOX_WIDTH) << "│\n";

	std::cout << "├────────────────────────────────────────────┤\n";

	// =========================
	// 요일
	// =========================
	std::cout << "│ ";
	std::cout << centerAlign(" Sun", 6)
		<< centerAlign("Mon", 6)
		<< centerAlign("Tue", 6)
		<< centerAlign("Wed", 6)
		<< centerAlign("Thu", 6)
		<< centerAlign("Fri", 6)
		<< centerAlign(" Sat", 6);
	std::cout << " │\n";

	std::cout << "│ " << std::string(BOX_WIDTH - 2, ' ') << " │\n";

	// =========================
	// 시작 공백
	// =========================
	int currentCol = 0;

	// 첫 줄 시작
	std::cout << "│ ";

	// 시작 공백
	for (int i = 0; i < startDay; i++) {
		std::cout << std::string(6, ' ');
		currentCol++;
	}

	// =========================
	// 날짜 출력 (핵심 유지)
	// =========================
	for (int day = 1; day <= daysInMonth; day++) {

		std::string base = selectedDate.substr(0, 8);

		std::string checkDate;
		if (day < 10)
			checkDate = base + "0" + std::to_string(day);
		else
			checkDate = base + std::to_string(day);

		bool hasTodo = hasTodoOnDate(checkDate);
		bool isToday = (checkDate == today);

		std::string output;

		if (isToday)
			output = "[" + std::to_string(day) + "]";
		else if (hasTodo)
			output = std::to_string(day) + "*";
		else
			output = std::to_string(day);

		std::cout << centerAlign(output, 6);
		currentCol++;

		// 🔥 7칸 채우면 줄 종료
		if (currentCol == 7) {
			std::cout << " │\n";
			currentCol = 0;

			// 다음 줄 시작 (마지막 줄 제외)
			if (day != daysInMonth) {
				std::cout << "│ ";
			}
		}
	}

	if (currentCol != 0) {
		for (int i = currentCol; i < 7; i++) {
			std::cout << std::string(6, ' ');
		}
		std::cout << " │\n";
	}

	// =========================
	// BOTTOM BOX
	// =========================
	std::cout << "├────────────────────────────────────────────┤\n";
	std::cout << "│   * = [TO-DO] 있음       [ ] = 오늘 날짜   │\n";
	std::cout << "│                                            │\n";
	std::cout << "│   ♡        ♡        ♡        ♡        ♡    │\n";
	std::cout << "└────────────────────────────────────────────┘\n\n";
}

// 날짜 상세 화면
void TaskManager::showDateDetail() {

	// 캘린더 먼저 보여주기
	showCalendar();

	std::cout << "================= " << selectedDate << " =================\n";

	std::cout << "\n[일정]\n";
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == selectedDate && tasks[i].type == 0) {
			std::cout << "- " << tasks[i].time << " " << tasks[i].title << "\n";
		}
	}

	std::cout << "\n\n";

	std::cout << "\n[할일]\n";
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == selectedDate && tasks[i].type == 1) {

			std::cout << "- ";

			std::cout << tasks[i].title;

			if (tasks[i].isDone)
				std::cout << " [DONE]";

			std::cout << " (우선순위: " << tasks[i].priority << ")\n";
		}
	}

	std::cout << "\n";

	std::cout << "\n----------------------------------------------\n";
	std::cout << "[A] 추가          [E] 수정          [D] 삭제\n";
	std::cout << "[S] 날짜 이동     [B] 뒤로          [0] 종료\n";
	std::cout << "----------------------------------------------\n";
}


// 메뉴 컨트롤 함수
void TaskManager::calendarLoop() {

	while (true) {

		showCalendar();

		std::cout << "==============================================\n";
		std::cout << "\n[1] 날짜 선택\n";
		std::cout << "[2] [TO-DO] LIST\n";
		std::cout << "[0] 종료\n\n";

		int choice = safeInputInt("[입력]: ", -1);

		if (choice == 0)
			break;

		// =========================
		// 1. 날짜 선택
		// =========================
		if (choice == 1) {

			while (true) {
				std::cout << "날짜 입력 (YYYY-MM-DD): ";
				std::getline(std::cin, selectedDate);

				if (isValidDate(selectedDate))
					break;

				std::cout << "❌ 올바른 날짜 형식이 아닙니다.\n";
			}

			// 상세 화면 루프
			while (true) {
				showDateDetail();

				std::string input;
				std::getline(std::cin, input);

				if (input == "A" || input == "a") addTask();
				else if (input == "E" || input == "e") editTask();
				else if (input == "D" || input == "d") deleteTask();
				else if (input == "B" || input == "b") break;
				else if (input == "S" || input == "s") {
					std::string newDate;

					while (true) {
						std::cout << "검색할 날짜 입력 (YYYY-MM-DD): ";
						std::getline(std::cin, newDate);

						if (newDate.empty()) break;

						if (isValidDate(newDate)) {
							selectedDate = newDate;
							break;
						}
						else {
							std::cout << "❌ 올바른 날짜 형식이 아닙니다.\n";
						}
					}

					continue;        // 상세 루프 유지하면서 바로 갱신
				}
				else if (input == "0") exit(0);
			}
		}



		// =========================
		// 2. [TO-DO] LIST
		// =========================
		else if (choice == 2) {
			showTodayTodo();
		}
	}
}

void TaskManager::showTodayTodo() {

	system("cls");

	std::string today = getToday();

	std::vector<Task> todayTodos;

	// 1. 오늘 할일만 필터
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].type == 1 && tasks[i].date == today) {
			todayTodos.push_back(tasks[i]);
		}
	}

	// 2. 정렬 (미완료 먼저 + 우선순위)
	std::sort(todayTodos.begin(), todayTodos.end(), [](Task a, Task b) {

		if (a.isDone != b.isDone)
			return !a.isDone; // 미완료 먼저

		return a.priority < b.priority;
		});

	std::cout << "┌──────────────────────────────────────────┐\n";
	std::cout << "│                TO-DO LIST                │\n";
	std::cout << "├──────────────────────────────────────────┤\n\n";

	for (int i = 0; i < todayTodos.size(); i++) {

		std::cout << "  " << i + 1 << ". ";

		if (!todayTodos[i].isDone)
			std::cout << "❗ ";

		std::cout << todayTodos[i].title;

		if (todayTodos[i].isDone)
			std::cout << " [DONE]";

		std::cout << "\n      └─ 우선순위: ";

		if (todayTodos[i].priority == 1) std::cout << "★★★";
		else if (todayTodos[i].priority == 2) std::cout << "★★";
		else std::cout << "★";

		std::cout << "\n\n";
	}

	if (todayTodos.empty()) {
		std::cout << "          오늘 할 일이 없습니다.\n";
		pauseScreen(); // 추가
		return;        // 바로 뒤로
	}

	std::cout << "\n├──────────────────────────────────────────┤\n";
	std::cout << "\n[1] 완료 처리";
	std::cout << "\n[2] 뒤로가기\n\n";


	int choice = safeInputInt("[입력]: ");

	if (choice == 1) {
		toggleDone();
	}
	else if (choice == 2) {
		return;
	}
}

