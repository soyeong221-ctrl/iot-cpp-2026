// Ch1-4. 인라인(inline) 함수

#include <iostream>

/*inline int SQUARE(int x) {

	return x * x;
}

inline double SQUARE(double x) {

	return x * x;
}
*/

// tmeplate으로 제네릭 프로그램 구현

template <typename T>
inline T SQUARE(T x) {

	return x * x;
}


int main(void) {

	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(3.15) << std::endl;
	
	return 0;
}
