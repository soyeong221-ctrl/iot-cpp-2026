// 260227 c++ Chapter1
// 클래스는 내가 만든 하나의 자료형.
// // Ch1-1.printf와 scanf를 대신하는 입출력 방식

#include <iostream>

int main()
{
	/*
	int num = 20;
	//printf("num: %d", num);
	std::cout << "Hello World" << std::endl;	//std: namespace, cout: 객체, endl: 객체 
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << num << ' ' << 'A';	// 
	std::cout << ' ' << 3.14 << std::endl;

	int val1;
	std::cout << "첫 번째 숫자 입력: ";
	std::cin >> val1;

	int val2;
	std::cout << "두 번째 숫자 입력: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈 결과: " << result << std::endl;
	*/

	
	/*std::string name;
	std::cout << "이름 입력: ";
	std::cin >> name;

	int age;
	std::cout << "나이 입력: ";
	std::cin >> age;

	std::cout << "이름: " << name << std::endl;
	std::cout << "나이: " << age << std::endl;
	*/

	/*std::string name;
	int age;

	std::cout << "이름, 나이 입력(예: ㅇㅇㅇ 20): ";
	std::cin >> name >> age;

	std::cout << "이름: " << name << " 나이: " << age << std::endl;
	*/

	// 배열 기반의 문자열 입출력
	// 배열 이름은 주소
	// 배열에 사용하는 제어문은 for문

	char name[100];
	char lang[200];

	std::cout << "이름은 무엇입니까? ";
	std::cin >> name;

	std::cout << "좋아하는 프로그래밍 언어는 무엇인가요? ";
	std::cin >> lang;

	std::cout << "내 이름은 " << name << "입니다.\n";
	std::cout << "좋아하는 언어는 " << lang << "입니다." << std::endl;


	// Ch1-2. 함수 오버로딩: 이름이 같지만 입력 다르면 다른 함수
	// 동일한 이름의 함수 구현 완료
	// 기준: 입력 (출력은 상관 없음)
	// overloading(다중정의) vs overriding(상속관계에 있는 함수 재정의)
	// c++는 상속, 다형성, 객체, 캡슐화 등 ~ p.28




	return 0;
}