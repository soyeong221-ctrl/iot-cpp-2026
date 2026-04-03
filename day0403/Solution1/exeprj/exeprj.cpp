// template - 다형성을 위함

#include <iostream>

// 클래스 템플릿 선언
//template <typename T>
//class A {
//	T num;
//public:
//	A(T data) : num(data) {}
//};

// 함수 템플릿 선언
//template <typename T, typename T1>
//T add(T a, T1 b) {
//	return a + b;
//}

// swap 함수 템플릿 선언(참조 매개변수 사용)
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	// double res = add<double>(10.3, 20.2); // 템플릿 함수 호출

	// cout << "Result: " << res << endl;

	// A<int> a(10);
	// A<double> d(10.5);
	
	int a = 10, b = 20;
	std::cout << "호출 전 a: " << a << ", b: " << b << std::endl;
	swap<int>(a, b);
	std::cout << "호출 후 a: " << a << ", b: " << b << std::endl;

	return 0;

}