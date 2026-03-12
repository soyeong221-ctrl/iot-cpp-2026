#include <iostream>
using namespace std;

// 전역변수 선언 기본값으로 초기화
bool sw; // 0
char c1; // 0
long l1; // 0
float f1;//0.0 
double d1;//0.0

int main()
{
	// 지역 변수 반드시 할당이 되어야 한다.(초기화되어야 한다.)
	bool b1 = -1;
	char first = 'A';
	char second = 48;  // 0 48, a 97, A 65
	cout << "b1: " << boolalpha << b1 << endl;
	cout << "first : " << first << endl;
	cout << "second : " << second << endl;
	cout << sizeof(int) << endl;
	cout << "sw : " << sw << endl;
	cout << "c1 : " << c1 << endl;
	cout << "l1 : " << l1 << endl;
	cout << "f1 : " << showpoint <<f1 << endl;
	cout << "d1 : " << showpoint << d1 << endl;
}

