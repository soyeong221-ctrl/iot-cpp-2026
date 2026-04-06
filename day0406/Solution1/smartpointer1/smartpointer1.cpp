#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Myclass {
public:
	Myclass() {
		std::cout << "Myclass 객체 생성" << std::endl;
	}
};


int main() {
	int* p = new int;
	*p = 10;
	std::cout << "*p: " << *p << std::endl;

	delete p;

	// int * p2 = new int(20);

	int* arr = new int[5];
	arr[0] = 10;
	std::cout << "arr[0]: " << arr[0] << std::endl;

	delete[] arr;

	Myclass* obj = new Myclass();

	delete obj;

	std::unique_ptr<char[]> name = std::make_unique<char[]>(10);
	std::strcpy(name.get(), "홍길동");
	std::cout << name.get() << std::endl;


	return 0;
}