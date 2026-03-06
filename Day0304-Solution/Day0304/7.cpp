// 동적할당이 되는 class 설계. 생성자/복사생성자/이동생성자/소멸자 명시적으로 나타내기

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class MyClass {
private: 
	char *name;
	int age;

public:

	MyClass() {          // 기본 생성자
		cout << "기본 생성자 호출!" << endl;
		name = nullptr;  // 문자열 초기화
		age = 0;         // 나이 초기화
	}

	MyClass(const char* name, int age) {
		cout << "일반 생성자 호출!" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	MyClass(const MyClass &other) {
		cout << "복사 생성자 호출!" << endl;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->age = other.age;
	}

	MyClass(MyClass &&other) noexcept {
		cout << "이동 생성자 호출!" << endl;
		this->name = other.name;
		this->age = other.age;
		other.name = nullptr;		// 이동 후 원본 객체의 name을 nullptr로 설정
		other.age = 0;
	}

	void showMyClass() {
		cout << "Name: " << name << ", Age: " << age << endl;
	}

	~MyClass() {
		cout << "소멸자 호출!" << endl;
		delete[] name;
	}


};

int main() {

	MyClass obj;  // 기본 생성자 호출
	obj.showMyClass();

	MyClass obj1("Love", 20);
	obj1.showMyClass();

	MyClass obj2(obj1);
	obj2.showMyClass();

	MyClass obj3(move(obj1));
	obj3.showMyClass();

	return 0;
}