// 프로그램 실행

#include <iostream>
#include "TaskManager.h"

int main() {

	TaskManager manager;

	manager.load();
	manager.calendarLoop();

	std::cout << "\nPlanMate 종료\n";

		return 0;
	}