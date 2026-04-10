#include <iostream>
#include <vector>	// 여러 개 저장을 위해서
#include <algorithm>
#include <fstream>	// 파일 입출력
#include <limits>
#include <ctime>
#include "Task.h"
#include "TaskManager.h"



// waitEnter(); 추가
void waitEnter() {
	std::cout << "\n(Enter 눌러 계속..♥)";
	std::cin.get();
}


int main() {

	TaskManager manager;

	manager.load();

	int choice;	// 사용자가 선택한 메뉴 저장

	while (true) {	// 프로그램 계속 실행

		system("cls");

		std::cout << "==== PlanMate ====" << std::endl;
		std::cout << "\n1. 전체 일정 보기" << std::endl;
		std::cout << "2. 날짜별 일정 보기" << std::endl;
		std::cout << "3. 일정 추가" << std::endl;
		std::cout << "4. 일정 삭제" << std::endl;
		std::cout << "5. 일정 수정" << std::endl;
		std::cout << "6. [TO-DO] → [DONE]" << std::endl;
		std::cout << "0. 종료" << std::endl;

		std::cout << "\n선택: ";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// 1번: 전체 일정 보기
		if (choice == 1) {
			manager.showAllTasks();
			waitEnter();
		}

		// 2번: 날짜별 일정 보기
		else if (choice == 2) {
			manager.showTasksByDate();
			waitEnter();
		}

		// 3번: 일정 추가
		else if (choice == 3) {
			manager.addTask();
			waitEnter();
		}

		// 4번: 일정 삭제
		else if (choice == 4) {
			manager.deleteTask();
			waitEnter();
		}

		// 5번: 일정 수정
		else if (choice == 5) {
			manager.editTask();
			waitEnter();
		}

		// 6번: 완료 [TO-DO] → [DONE]
		else if (choice == 6) {
			manager.toggleDone();
			waitEnter();
		}

		// 0번: 종료
		else if (choice == 0) {
			break;
		}
	
	}

	return 0;
}