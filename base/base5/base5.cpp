// Chapter 02-1. Chapter 02의 시작에 앞서

#include <iostream>
using namespace std;

int main(void) {

	//int num1 = 10;
	//num1 = 20;
	//cout << num1 << endl;

	//const int num2 = 10;
	//cout << num2 << endl;

	//int num2 = 20;
	//const int* p1 = &num2;

	//cout << *p1 << endl;
	//cout << num2 << endl;

	// *p1 = 10;
	/*
	int num3 = 22;
	p1 = &num3;
	cout << *p1 << endl;

	int n2 = 40;
	int* const p2 = &n2;

	*p2 = 50;
	//p2 = &n3;
	cout << *p2 << endl;
	*/

	// Ch2-2. 새로운 자료형 bool *자료 참고
	
	// Ch2-3. 참조자의 이해
	// 반드시 초기화 필요

	/*
	int num1 = 1020;
	int& num2 = num1;

	num2 = 3047;
	cout << "VAL: " << num1 << endl;
	cout << "REF: " << num2 << endl;

	cout << "VAL: " << &num1 << endl;
	cout << "REF: " << &num2 << endl;
	*/

	int num=12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;
	return 0;









	return 0;
}