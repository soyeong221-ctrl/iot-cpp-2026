#include <iostream>

struct B;

struct A {
	std::shared_ptr<B> b_ptr;
};

struct B {
	// std::shared_ptr<A> a_ptr;	// 강한 참조
	/* 순환 참조 해결 */
	std::weak_ptr<A> a_ptr;			// 약한 참조

};


int main() {
	std::shared_ptr<A> a(new A());
	std::shared_ptr<B> b(new B());

	a->b_ptr = b; // A 객체가 B 객체를 가리킴
	b->a_ptr = a;

	std::cout << "count: " << a->b_ptr.use_count() << std::endl;
	std::cout << "count: " << b->a_ptr.use_count() << std::endl;

	return 0;
}