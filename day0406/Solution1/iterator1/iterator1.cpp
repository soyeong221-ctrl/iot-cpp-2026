// iterator(반복자): 컨테이너(자료구조) 내부의 데이터에 접근할 수 있는 포인터
// vector<int>::iterator it; // 순방향 반복자 선언, 생략하고 auto it;로 선언해도 됨

# include <iostream>
# include <vector>

int main() {
	std::vector<int> v = { 10, 20, 30, 40, 50 };
	
	std::vector<int>::iterator it;	// 반복자 선언
		for (it = v.begin(); it != v.end(); it++) {
			std::cout << *it << " " << std::endl;
		}
		std::cout << std::endl;

		for (auto it = v.begin(); it != v.end(); it++) {
			std::cout << *it << " " << std::endl;
		}
		std::cout << std::endl;

		std::vector<int>::reverse_iterator rit;  // 역방향 반복자 선언
		for (rit = v.rbegin(); rit != v.rend(); rit++) {
			std::cout << *rit << " " << std::endl;
		}
		std::cout << std::endl;

		for (auto rit = v.rbegin(); rit != v.rend(); rit++) {
			std::cout << *rit << " " << std::endl;
		}

	return 0;
}