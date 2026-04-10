/* main 정리 전 함수


// 1번: 전체 일정 보기
if (choice == 1) {
	std::cout << "\n=== 전체 일정 ===" << std::endl;

	sort(tasks.begin(), tasks.end(), [](Task a, Task b) {	// tasks 정렬

		// 1순위: 날짜
		if (a.date != b.date) {
			return a.date < b.date;
		}

		// 2순위: 타입(일정 먼저)
		if (a.type != b.type) {
			return a.type < b.type;	// 일정(0) -> 할일(1)
		}

		// 3순위: 우선순위(높은 거 먼저)
		return a.priority < b.priority;
		});

	//그룹 출력
	std::string lastDate = "";	// 이전 날짜 기억용 변수

	for (int i = 0; i < tasks.size(); i++) {

		if (tasks[i].date != lastDate) {
			std::cout << "\n=== " << tasks[i].date << " ===" << std::endl;
			lastDate = tasks[i].date;	// 날짜 기억해둬서 바뀔 때만 제목 나옴
		}
		if (tasks[i].type == 0) {
			std::cout << "[일정] ";
		}
		else {
			if (tasks[i].isDone)
				std::cout << "[DONE] ";
			else
				std::cout << "[TO-DO] ";
		}
		std::cout << tasks[i].title;

		if (tasks[i].type == 1) {
			std::cout << "(우선 순위: " << tasks[i].priority << ")";
		}
		std::cout << std::endl;
	}

	waitEnter();
}

// 2번: 날짜별 일정 보기
else if (choice == 2) {

	if (tasks.empty()) {
		std::cout << "일정이 없습니다." << std::endl;
		waitEnter();
		continue;
	}

	std::string selectedDate;
	std::cout << "날짜 입력 (YYYY-MM-DD): ";
	std::cin >> selectedDate;

	std::cout << "\n=== " << selectedDate << " 일정 ===" << std::endl;

	bool found = false;

	for (int i = 0; i < tasks.size(); i++) {
		if (tasks[i].date == selectedDate) {

			std::cout << i + 1 << ". ";

			if (tasks[i].type == 0) {
				std::cout << "[일정]";
			}
			else {
				std::cout << (tasks[i].isDone ? "[DONE] " : "[TO-DO] ");
			}

			std::cout << tasks[i].title;

			if (tasks[i].type == 1) {
				std::cout << " / 우선순위: " << tasks[i].priority;
			}

			std::cout << std::endl;

			found = true;
		}
	}

	if (!found) {
		std::cout << "해당 날짜에 일정이 없습니다." << std::endl;
	}

	waitEnter();
}


// 3번: 일정 추가

else if (choice == 3) {
	Task t;

	int typeChoice;

	std::cout << "\n[1.일정]  [2.할일] 中 선택: ";
	std::cin >> typeChoice;

	t.type = (typeChoice == 1) ? 0 : 1;		// 삼항 연산자: 조건 ? 참일 때 값 : 거짓일 때 값

	std::cout << "내용 입력: ";
	std::cin.ignore();	// 버퍼 비우기
	getline(std::cin, t.title);	// 전체 문장 입력

	std::cout << "날짜 입력 (YYYY-MM-DD): ";
	std::cin >> t.date;

	std::cout << "우선순위 (1~3): ";
	std::cin >> t.priority;

	t.isDone = false;

	tasks.push_back(t);
	saveTasks(tasks);

	std::cout << "일정 추가 완료!" << std::endl;
	waitEnter();
}


// 4번: 일정 삭제
else if (choice == 4) {

	if (tasks.empty()) {	// 리스트가 비었는지 확인
		std::cout << "삭제할 일정이 없습니다." << std::endl;
		waitEnter();
		continue;
	}

	std::cout << "\n=== 삭제할 일정 선택 ===" << std::endl;

	//목록 보여주기

	//for (int i = 0; i < tasks.size(); i++) {
	//	std::cout << i + 1 << ". ";
	//	std::cout << tasks[i].title << " / ";
	//	std::cout << tasks[i].date << " / ";
	//	std::cout << tasks[i].priority << std::endl;
	

	printSimpleTasks(tasks);

	int num;  // 사용자가 선택한 번호 저장
	std::cout << "삭제할 번호 입력: ";
	std::cin >> num;

	// 핵심: 인덱스 보정
	int index = num - 1;

	// 예외 처리
	if (index < 0 || index >= tasks.size()) {
		std::cout << "잘못된 번호입니다." << std::endl;
	}

	else {
		tasks.erase(tasks.begin() + index);
		saveTasks(tasks);
		std::cout << "삭제 완료!" << std::endl;
	}
	waitEnter();
}

// 5번: 일정 수정
else if (choice == 5) {

	if (tasks.empty()) {
		std::cout << "수정할 일정이 없습니다." << std::endl;
		waitEnter();
		continue;
	}

	std::cout << "\n=== 수정할 일정 선택 ===" << std::endl;
	printSimpleTasks(tasks);


	int num;
	std::cout << "번호 선택: ";
	std::cin >> num;

	int index = num - 1;

	if (index < 0 || index >= tasks.size()) {
		std::cout << "잘못된 번호입니다." << std::endl;
		waitEnter();
		continue;
	}

	Task& t = tasks[index];	//참조

	std::cout << "\n1. 제목 수정\n2. 날짜 수정\n3.우선순위 수정\n선택: ";
	int editChoice;
	std::cin >> editChoice;

	std::cin.ignore();

	if (editChoice == 1) {
		std::cout << "새 제목: ";
		getline(std::cin, t.title);
	}
	else if (editChoice == 2) {
		std::cout << "새 날짜 (YYYY-MM-DD): ";
		std::cin >> t.date;
	}
	else if (editChoice == 3 && t.type == 1) {
		std::cout << "새 우선순위 (1~3): ";
		std::cin >> t.priority;
	}
	else {
		std::cout << "잘못된 선택입니다." << std::endl;
		waitEnter();
		continue;
	}

	saveTasks(tasks);
	std::cout << "수정 완료!" << std::endl;
	waitEnter();
}


// 6번. 완료 [TO-DO] → [DONE]
else if (choice == 6) {

	if (tasks.empty()) {
		std::cout << "일정이 없습니다." << std::endl;
		waitEnter();
		continue;
	}

	std::cout << "\n=== 완료 상태 변경 ===" << std::endl;


	//목록 출력
	
	//for (int i = 0; i < tasks.size(); i++) {
		std::cout << i + 1 << ". ";

		if (tasks[i].type == 0) {
			std::cout << "[일정] ";
		}
		else {

			if (tasks[i].isDone)
				std::cout << "[DONE] ";
			else
				std::cout << "[TO-DO] ";
		}

		std::cout << tasks[i].title << std::endl;
	}
	//

	printSimpleTasks(tasks);

	int num;
	std::cout << "번호 선택 : ";
	std::cin >> num;

	int index = num - 1;

	if (index < 0 || index >= tasks.size()) {
		std::cout << "잘못된 번호입니다." << std::endl;
	}
	else {
		if (tasks[index].type == 1) {
			tasks[index].isDone = !tasks[index].isDone;	// 상태 토글
			saveTasks(tasks);
			std::cout << "상태 변경 완료!" << std::endl;
			waitEnter();
		}
		else {
			std::cout << "일정은 완료 상태 변경 불가" << std::endl;
		}
		waitEnter();

	}
}




// 0번: 종료
else if (choice == 0) {
	std::cout << "프로그램 종료" << std::endl;
	break;
}

else {
	std::cout << "잘못된 입력입니다." << std::endl;
}

	}

	return 0;
}

*/