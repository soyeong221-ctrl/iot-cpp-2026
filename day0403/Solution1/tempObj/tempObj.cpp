# include <iostream>
using namespace std;

class Myclass {
private:
	int a;
public:
	Myclass(int aa) : a(aa) {
		cout << "생성자: " << a << endl;
	}
	~Myclass() {
		cout << "소멸자: " << a << endl;
	}
	Myclass(const Myclass& other) : a(other.a) {
		cout << "복사 생성자: " << a << endl;
	}
};


int main() {

	// Myclass obj(10);
	Myclass obj1 = Myclass(20);	// = Myclass obj1(20) , R value: 임시 객체 아님.

	Myclass(30);	// R value: 임시 객체 생성

	return 0;
}