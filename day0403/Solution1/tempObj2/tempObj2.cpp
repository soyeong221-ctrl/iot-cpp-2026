# include <iostream>
using namespace std;

class Myclass {
private:
	int n;
public:
	Myclass(int aa) : n(aa) {
		cout << n << "생성자" << endl;
	}
	~Myclass() {
		cout << n << "소멸자" << endl;
	}
	void set(int aa) {
		n = aa;
		cout << "set(" << n << ")" << endl;
	}

};


int main() {

	// Myclass* obj1 = &Myclass(10);	// 임시 객체는 주소 가져올 수 없음

	Myclass obj = Myclass(10); 
	obj.set(22);

	const Myclass& obj1 = Myclass(30); // 읽기전용
	// obj1.set(30);	// const 객체는 멤버 함수 호출 불가

	Myclass&& obj2 = Myclass(40); // 정상적으로 R value 참조 - 임시 객체를 참조하고 수명을 연장할 수 있음, 수정가능
	obj2.set(44);

	cout << "bye" << endl;

	return 0;
}