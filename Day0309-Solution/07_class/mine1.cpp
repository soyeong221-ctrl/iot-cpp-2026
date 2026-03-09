#include <iostream>
using namespace std;

/*
class Circle {
private:
	static double radius;
public:
	double getRadius() const { return radius; } // Getter: 값을 읽기만 하므로 const 가능
	void setRadius(double r) { radius = r; } // Setter: 값을 수정해야 하므로 const 제거
	// 일반 멤버 함수: radius에 접근해야 하므로 static 제거
	static double getAreaOfCircle() { return radius * radius * 3.14; }	// static은 같은 static끼리만
};
double Circle::radius = 0.0;

int main() {
	Circle c1;
	c1.setRadius(10.0);
	cout << "반지름: " << c1.getRadius() << endl;
	// 함수 호출 시 반드시 ()를 붙여야 함
	cout << "넓이: " << c1.getAreaOfCircle() << endl;
}

*/