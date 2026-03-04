// 깊은 복사(deep copy)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

/*
class Person {
private:
	char* name;
	int age;

public:
	Person(const char* name, int age) {
		printf("생성자 호출!\n");
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	Person(const Person& other) {
		printf("복사생성자 호출!\n");
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->age = other.age;
	}

	void showPerson() {
		printf("이름: %s, 나이: %d\n", name, age);
	}

	~Person() {
		printf("소멸자 호출: %s\n", name);
	delete[] name;
}

};


int main() {
	Person man("LOVE", 20);
	man.showPerson();

	Person cpman(man);
	cpman.showPerson();

	Person woman("CUTE", 20);
	woman.showPerson();

	return 0;
}

*/