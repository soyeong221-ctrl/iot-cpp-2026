// vector

#include <iostream>
#include <vector>

using namespace std;


int main() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	/* 출력: 일반적이고 간결한 형태 */
	for (auto i = 0; i < v.size(); i++) {
		cout << v[i] << " " << endl;
		cout << v.at(i) << " " << endl;
	}
	cout << endl;

	/* 출력: vector 크기를 나타내는 표준화된 부호없는 정수 타입 */
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " " << endl;
		cout << v.at(i) << " " << endl;
	}
	cout << endl;

	/* 출력: 범위기반 for */
	for (auto i : v) {
		cout << i << " " << endl;
	}
	cout << endl;

	/* 출력: vector 컨테이너의 반복자 사용하기 */
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " " << endl;
	}



	return 0;
}