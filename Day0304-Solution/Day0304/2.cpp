#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

/*
class Person {
private:	
	char name[20];
	int age;
public:
	Person(const char *name, int age) {
		printf("생성자 호출\n");
		strcpy(this->name, name);
		this->age = age;
	}
	void viewPerson() {
		cout << "Name: " << name << ", Age: " << age << endl;	// printf("name: %s, age: %d\n", m_name, this->age);
	}
};

int main() {

	Person p("홍길동", 30);
	p.viewPerson();

	Person p1 = p; // 객체 복사해서 생성. (복사 생성자 호출) 
	p1.viewPerson();

	Person p2(p); // 객체 복사해서 생성. (복사 생성자 호출)
	p2.viewPerson();

	return 0;
}
*/