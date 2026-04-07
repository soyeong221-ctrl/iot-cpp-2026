// shared_ptr: 소유권을 공유하는 스마트 포인터(여러 포인터가 하나의 객체를 공유할 수 있음).
// 객체의 참조 카운팅을 관리하여 여러 포인터가 동일한 객체를 공유하게 한다. 즉, 소유권 공유
// 참조 카운터가 0이 되면 메모리가 해제된다.

#include <iostream>

/*
class Myclass {
public:
	Myclass() {
		std::cout << "Myclass 호출: 객체 생성" << std::endl;
	}
	~Myclass() {
		std::cout << "~Myclass 호출: 객체 소멸" << std::endl;
	}
	void func() {
		std::cout << "Hi shared_ptr!" << std::endl;
	}
};

int main() {
	std::shared_ptr<Myclass> ptr = std::make_shared<Myclass>(); // 객체 생성과 동시에 shared_ptr로 관리
	std::shared_ptr<Myclass> ptr2 = ptr; // 객체 공유 가능(참조 카운트 증가)
	std::cout << std::endl;

	std::cout << "ptr과 ptr2는 객체 공유중" << std::endl;
	std::cout << "ptr count: " << ptr.use_count() << std::endl;
	std::cout << "ptr2 count: " << ptr2.use_count() << std::endl;

	ptr->func();
	ptr2->func();

	return 0;
}


*/
