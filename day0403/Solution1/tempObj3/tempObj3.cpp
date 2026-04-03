#include <iostream>
using namespace std;

class Myclass {
private:
	int n;
public:
	Myclass(int aa) : n(aa) {
		cout << this << " 생성자" << endl;
	}
	~Myclass() {
		cout << this << " 소멸자" << endl;
	}
	Myclass(const Myclass& other) : n(other.n) {
		cout << this << " 복사 생성자" << endl;
	}
	void set(int aa) {
		n = aa;
		cout << "set(" << n << ")" << endl;
	}
};

Myclass func(const Myclass& ob) {
	cout << &ob << " func()" << endl;
	return ob;
}

int main() {

	Myclass obj(10);
	cout << endl;

	// Myclass obj1(func(obj));
	// Myclass obj2(obj);	// obj2는 복사생성자 호출로 객체 생성
	cout << endl;

	func(obj);
	cout << endl;

	cout << "bye" << endl;


	return 0;
}