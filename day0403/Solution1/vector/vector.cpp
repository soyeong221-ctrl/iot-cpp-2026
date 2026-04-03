#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<int> v;								// 크기가 0인 벡터
	vector<int> v1(10);							// 크기가 10인 벡터
	vector<int> v2 = { 1, 2, 3, 4, 5 };			// 크기가 5인 벡터

	cout << "v size: " << v.size() << endl;
	cout << "v1 size: " << v1.size() << endl;
	cout << "v2 size: " << v2.size() << endl;

	cout << "v 벡터 객체의 메모리 크기: " << sizeof(v) << endl;
	cout << "v1 벡터 객체의 메모리 크기: " << sizeof(v1) << endl;
	cout << "v2 벡터 객체의 메모리 크기: " << sizeof(v2) << endl;

	// cout << "v[0]: " << v[0] << endl;

	for (auto i : v2) {				// 범위 기반 for문
		cout << i << endl;			// i는 인덱스가 아니라 요소값을 저장하는 변수
		// cout << v2[i] << endl;
		cout << endl;
	}

	cout << "v2의 첫번 째 요소값: " << *v2.begin( ) << endl;
	cout << "v2의 마지막 요소값: " << *(v2.end() - 1) << endl;

	return 0;
}