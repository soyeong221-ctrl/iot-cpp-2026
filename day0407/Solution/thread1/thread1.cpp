#include <iostream>
#include <thread>

/*
멀티프로세스(Multi - Process)
→ 프로그램(프로세스)을 여러 개 실행 / 각각 완전히 독립된 메모리 공간 사용

멀티스레드(Multi - Thread)
→ 하나의 프로그램 안에서 작업 흐름(스레드) 여러 개 실행 / 메모리를 공유하면서 동시에 작업
*/

/*
void work() {
	for (int i = 1; i <= 20; i++) {
		std::cout << "작업 스레드: " << i << std::endl;
	}
}

int main() {

	std::thread t(work);	// work 함수를 별도의 스레드에서 실행
	// work();
	for (auto i = 1; i <= 20; i++) {
		std::cout << "메인 스레드: " << i << std::endl;
	}

	t.join(); 
	return 0;
}

*/