//override, 형변환

#include <iostream>
using namespace std;

/*
class P {
public:
	void f() { cout << "P::f" << endl; }			// Output: P::f
	// virtual void f() { cout << "P::f" << endl; } // Output: C::f
};

class C : public P {
public:
	virtual void f() { cout << "C::f" << endl; }	// 인스턴스 생성시
};


int main() {
	// 내부 클래스(Inner Class): 변수처럼 사용가능한 클래스
	class A {
	public:
		virtual void f() { cout << "A::f" << endl; } // 조상의 함수에 virtual을 붙이면 각각의 인스턴스별로 f()가 호출됨
};
	class B : public A {
	public:
		void f() override { cout << "B::f" << endl; }
	};


								// 클라스 형변환
	A* a = new B();				// 자식이 부모로 가는 건 가능, 부모가 자식으로 가는 건 안 됨: 자부(O) 부자(X) 자부자(O)
	a->f(); // Output: B::f
	delete a;

	C c;
	c.f(); // Output: C::f

	P p;
	p.f(); // Output: P::f

	P* p2 = new C();
	p2->f(); // Output: P::f (because P::f is not virtual)

	// C* c1 = new P(); // 실행 x (부모가 자식으로 가는 것) p -> c x

	return 0;
}

*/