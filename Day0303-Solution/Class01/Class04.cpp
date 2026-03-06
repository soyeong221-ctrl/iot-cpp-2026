// Chap03-01 C++에서의 구조체
// C++ 클래스

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
class Human {
private:
	char name[20];
	int age;
	char job[20];

public:
	Human(){}
	Human(const char* aname, int aage, const char* ajob) {
		strcpy(name, aname);	// name = aname; // 배열은 대입 연산자 사용 불가
		age = aage;
		strcpy(job, ajob);
	}
	void show() {
		std::cout << "이름: " << name << ", 나이: " << age << ", 직업: " << job << endl;
	}
};

int main() {

	Human h("Yeong", 27, "student");
	// Human h1();
	Human h1;

	h.show();

	return 0;
}
*/