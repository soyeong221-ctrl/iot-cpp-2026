// 형변환(casting): 데이터 타입을 다른 타입으로 바꾸는 것

#include <iostream>
using namespace std;	// cout, cint, endl, string, thread
using std::cout;

/*
namespace A {
	void printAll() {
		cout << "A" << endl;
	}
}

namespace B {
	void printAll() {
		cout << "B" << endl;
	}
}

int main() {
	cout << "Hello World" << std::endl;
	A::printAll();
	B::printAll();
	unsigned short us = -2367;
	cout << us << endl;

	double x = 23.56;
	int y = 30;
	cout << "암묵적 자료형 변환 활용: " << x + y << endl; // 53.56;
	cout << "명시적 자료형 변환 활용: " << static_cast<int>(x) + y << endl; // 53
	cout << "명시적 자료형 변환 활용: " << (int)(x)+y << endl;

	double num1 = +numeric_limits<double>::max();	// numeric_limits<double>::max() → double이 표현할 수 있는 가장 큰 값
	double num2 = -numeric_limits<double>::max();
	cout << "부동소수점의 오버플로우: " << num1 * 1000 << endl;
	cout << "부동소수점의 오버플로우: " << num2 * 1000 << endl;



	return 0;
}

*/