#include <iostream>
#include <vector>	// 여러 개 저장을 위해서
#include "Task.h"

using namespace std;

int main() {

	vector<Task> tasks;		// 일정 여러 개 저장하는 공간


	// 일정1
	Task t1;
	t1.title = "C++ 공부";
	t1.date = "2026-04-07";
	t1.priority = 1;

	tasks.push_back(t1);	// 리스트에 추가


	// 일정2
	Task t2;
	t2.title = "운동";
	t2.date = "2026-04-08";
	t2.priority = 2;

	tasks.push_back(t2);

	
	//전체 출력
	cout << "=== 전체 일정 ===" << endl;

	for (int i = 0; i < tasks.size(); i++) {
		cout << i + 1 << ", ";
		cout << tasks[i].title << " / ";
		cout << tasks[i].date << " / ";
		cout << tasks[i].priority << endl;
	
	}

	return 0;
}