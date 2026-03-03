// Chapter 02-4. 참조자와 함수
// 리턴된 값 참조로 받아도 되고(복사), 일반 변수로 받아도 됨(다시 참조)

#include <iostream>
using namespace std;

/*
void change_val(int& n) {	// 참조 매개변수
	n = 20;
}

int main() {

	int num = 10;
	cout << num << endl;

	change_val(num);
	cout << num << endl;

	return 0;
}
*/

/*
int main() {

	int num = 10;
	int& ref = num;
	int* pnum = &num;

	num++;	// 11
	ref++;	// 12
	(*pnum)++;	// 13

	cout << "num: " << num << endl;
	cout << "ref: " << ref << endl;
	cout << "*pnum: " << *pnum << endl;

	cout << "&num: " << &num << endl;
	cout << "&ref: " << &ref << endl;

	return 0;
}
*/

// 상수참조자 레퍼런스
// 레퍼런스는 메모리 할당 x. 특정 공간 차지 x/\
// 새로운 공간이 아니라 그냥 같은 공간을 다른 이름으로 부르는 것.

/*
int main() {

	// int& ref = 4;
	const int& ref = 4; // 상수 레퍼런스로 선언하면 리터럴도 참조할 수 있다.

	cout << "ref: " << ref << endl;


	return 0;
}
*/

int funt(int n) {

	n++;
	return n;
}

int& funt1(int r) {		// 리턴타입이 레퍼런스. 출력이 레퍼런스.

	r++;
	return r;
}

int main() {

	int num = 10;
	
	int ret = funt(num);
	cout << ret << endl;

	int res = funt1(num);	// 리턴값 복사해서 사용
	cout << res << endl;

	int& ref = funt1(num);  // 리턴값 참조해서 사용
	cout << ref << endl;

	return 0;
}