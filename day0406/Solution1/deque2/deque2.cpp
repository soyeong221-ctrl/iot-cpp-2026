#include <iostream>
#include <deque>

int main() {

	std::deque<std::string> dq; // dq 객체 생성

	dq.push_front("tiger");
	dq.push_front("lion");
	dq.push_back("cats");

	std::deque<std::string>::iterator it; // 반복자 선언
	for (it = dq.begin(); it != dq.end(); it++) {
		std::cout << *it << " " << std::endl;
	}
	std::cout << std::endl;

	std::deque<std::string>::const_iterator cit; // const 반복자 선언
	for (cit = dq.cbegin(); cit != dq.cend(); cit++) {
		std::cout << *cit << " " << std::endl;
	}

	auto it2 = dq.begin() + 2;
	dq.insert(it2, 2, "INSERT");

	std::cout << std::endl;

	for (auto cit = dq.cbegin(); cit != dq.cend(); cit++) {
		std::cout << *cit << std::endl;
	}
	std::cout << std::endl;

	cit = dq.end();
	cit--; // 마지막 원소
	cit--; // 마지막 앞 원소
	dq.erase(cit);
	for (auto cit = dq.cbegin(); cit != dq.cend(); cit++) {
		std::cout << *cit << " " << std::endl;
	}
	std::cout << std::endl;

	for (auto element : dq) {		// 복사 사용
		std::cout << element << " " << std::endl;
	}
	std::cout << std::endl;

	for (auto& element : dq) {		// 참조 사용
		std::cout << element << " " << std::endl;
	}

	int a = 10;
	int b = 20;
	const int* pa = &a; // pa는 "값을 변경할 수 없는 포인터"
						// (*pa로 값 변경 불가, pa 자체는 다른 주소로 변경 가능)
	int* const pb = &b; // pb는 "주소를 변경할 수 없는 포인터"
						// (pb는 고정, 대신 *pb로 값 변경은 가능)
						// 
	// *pa = 100; // error: 데이터 상수이므로 변경 불가
	pa = &b;

	const int c = 10; // c는 상수이므로 값 변경 불가



	return 0;
}