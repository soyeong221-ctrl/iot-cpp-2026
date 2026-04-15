// 데이터 구조

#pragma once
#include <string>

class Task {
public:
	std::string title;
	std::string date;
	std::string time;
	int priority = 1;
	bool isDone = false;	// 완료 여부(true/false)
	int type = 0;	// 0 = 일정, 1 = 할일
};