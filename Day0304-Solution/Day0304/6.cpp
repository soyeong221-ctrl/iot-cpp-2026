// 이동생성자(Move Constructor): 객체의 자원을 다른 객체로 "이동"시키는 생성자.
// 복사 생성자는 객체의 자원을 "복사"하는 반면, 이동 생성자는 자원의 소유권을 이전하여 불필요한 복사를 방지하고 성능을 향상.
// std::move() 호출은 h객체를 rvalue로 변환하여 이동 생성자를 호출하도록 한다.`
// (주소를 새 객체로 복사하고 기존 객체는 null로 처리한다.(소유권 이전)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

/*
class Human {
private:
	char name[30];
	int age;
public:
	Human(const char *name, int age) {
		cout << "일반 생성자 호출!" << endl;
		strcpy(this->name, name);
		this->age = age;
	}

	Human(const Human &other) {
		cout << "복사 생성자 호출!" << endl;
		strcpy(this->name, other.name);
		this->age = other.age;	
	}

	Human(Human&& other) noexcept {
		cout << "이동 생성자 호출!" << endl;
		strcpy(this->name, other.name);
		this->age = other.age;
		other.name[0] = '\0'; // 이동 후 원본 객체의 name을 빈 문자열로 설정
		other.age = 0; // 이동 후 원본 객체의 age를 0으로 설정

	}

	void showHuman() {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};


int main() {
	Human h("LOVE", 20);	// 일반 생성자 호출
	h.showHuman();

	Human cph(h);			// 복사 생성자 호출
	cph.showHuman();

	Human mvh(move(h));		// move() 함수를 사용하여 이동 생성자 호출
	mvh.showHuman();


	return 0;
}
*/