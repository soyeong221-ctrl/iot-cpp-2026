#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> v;

	cout << "[ v[i], v.size(), v.capacity() ]" << endl;
	for (auto i = 0; i < 32; i++) {
		v.push_back(i + 1);
		cout << "[ " << v[i] << ", " << v.size() << ", " << v.capacity() << " ]" << endl;
	}

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v1.insert(v1.begin(), 10);
	v1.insert(find(v1.begin(), v1.end(), 3), 30);	// 원소 3 앞에 30 넣기

	for (auto i : v1) {
	
		cout << "i:" << i << endl;
	}
	return 0;
}

/*

v.push_back(7): 마지막 원소 뒤에 7 추가
v.insert(i, val): i 위치에 val 삽입
v.pop_back(): 마지막 원소 제거
v.size(): 벡터에 저장된 원소 개수 리턴
v.capacity(): 벡터에 저장가능한 공간의 크기 리턴
sizeof(v): 벡터 자체 고정된 크기를 바이트로 리턴
		   벡터에 원소를 추가할 때마다 size는 증가하지만 capacity는 증가하지 않고 일정한 범위마다 일정 배율로 늘어난다.
*/