// C++ MY 클래스

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 입력값 3개 받는 생성자 명시적으로 작성
// 함수 정의는 클래스 내부에서 작성

class MyClass {
private:
	int id;
	char name[20];
	int age;

public:
	MyClass(int aid, const char* aname, int aage);
	void getData();
};

	MyClass::MyClass(int aid, const char* aname, int aage) {
		id = aid;
		strcpy(name, aname);
		age = aage;
	}

	void MyClass::getData() {
		cout << "ID: " << id << ", 이름: " << name << ", 나이: " << age << endl;
	}
};


int main() {

	MyClass obj(201911786, "SoYeong", 27);

	obj.getData();

	return 0;
}