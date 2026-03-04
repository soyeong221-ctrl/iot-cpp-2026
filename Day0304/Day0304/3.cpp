// 복사생성자 - 객체를 복사하여 초기화하는 생성자

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
	Person(const char *name, int age) {			//constructor(생성자) - 클래스 이름과 같지만 출력이 없음
		printf("constructor!\n");
		strcpy(this->name, name);
		this->age = age;
	}

	Person(const Person &other) {				// copy construtctor(복사생성자) - 객체를 복사하여 초기화하므로 복사생성자 호출
		printf("copy constructor!\n");			// 입력이나 출력이 객체일 때는 복사생성자가 호출된다.
		strcpy(this->name, other.name);			// 복사생성자 인수는 상수 레퍼런스를 사용한다. (const Person &other)
		this->age = other.age;
	}

	~Person() {									// destructor(소멸자) / ~ 틸드
		printf("나는 소멸자입니다!\n");
	}

	void showPerson(){
		printf("이름: %s, 나이: %d\n", name, age);
	
	}
};


int main() {
	Person m("홍길동", 30);
	m.showPerson();

	Person m1(m);
	m1.showPerson();

	Person m2 = m;
	m2.showPerson();

	return 0;
}
*/

/*
기본생성자, 기본복사생성자, 기본소멸자는 디폴트로 제공된다.


*/
