// const와 함수 오버로딩

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

/*
class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {}

	SoSimple& AddNum(int n) {
		num += n;
		return *this;
	}

	void SimpleFunc() {

		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const {
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple& obj) {		// 매개변수가 const SoSimple& obj이므로 const 멤버 함수가 호출
		obj.SimpleFunc();
	}

int main(void) {
		SoSimple obj1(2);
		const SoSimple obj2(7);

		obj1.SimpleFunc();
		obj2.SimpleFunc();

		YourFunc(obj1);
		YourFunc(obj2);


		return 0;
	}

*/