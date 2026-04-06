#include <iostream>
#include <deque>

int main() {

	std::deque<int> dq;	// dq 객체 생성

	for (int i = 0; i <= 5; i++) {
		dq.push_back(i * 10);

	}

	std::deque<int>::iterator it;
	for (it = dq.begin(); it != dq.end(); it++) {
		std::cout << *it << " " << std::endl;
	}
	std::cout << std::endl;

	dq.push_front(1);	// 앞에 1 추가
	dq.push_front(2);
	dq.push_back(100);	// 뒤에 100 추가
	dq.push_back(200);

	for (it = dq.begin(); it != dq.end(); it++) {
		std::cout << *it << " " << std::endl;
	}
	std::cout << std::endl;

	

	return 0;
}