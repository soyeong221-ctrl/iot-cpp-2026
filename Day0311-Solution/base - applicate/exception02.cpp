#include <iostream>
#include <ctime>

using namespace std;

/*
// 함수 내부에서 throw하고 main 함수에서 catch하는 구조가 많이 사용.
int divide(int a, int b) {
	if ( b == 0) {
		throw "Division by zero is not allowed.";
	}
	return a / b;
}

int main() {
	srand(static_cast<unsigned int>(time(0))); // 랜덤 넘버 씨드 생성

	while (true) {
		int num1 = rand() % 10; // 0~9 사이 숫자
		int num2 = rand() % 10; // 0~9 사이 숫자
		try {
			cout << "Attempting to divide " << num1 << " by " << num2 << "..." << endl;
			int result = divide(num1, num2);
			cout << "Result: " << result << endl;
		}
		catch (const char* e) {
			cout << "Error: " << e << endl;
			break;
		}
	}
}
*/