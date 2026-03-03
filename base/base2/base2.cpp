// Ch1-3. 매개변수의 디폴트 값

#include <iostream>

int Adder(int num1 = 1, int num2 = 2);

int main(void) {

	std::cout << Adder() << std::endl;
	std::cout << Adder(5) << std::endl;
	std::cout << Adder(3, 5) << std::endl;

	return 0;
}

int Adder(int num1, int num2) {

	return num1 + num2;

}

/*
int MyFuncOne(int num = 7) {

	return num + 1;

}

int MyFuncTwo(int num1 = 5, int num2 = 7) {

	return num1 + num2;
}


int main() {

	int result = MyFuncOne();
	int result2 = MyFuncTwo();

	std::cout << "결과1: " << result << std::endl;
	std::cout << "결과2: " << result2 << std::endl;

	return 0;
}
*/