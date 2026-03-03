// c 복습2 - 메모리 맵 이해
#include <stdio.h>

int a;
int global_c = 100;
int func() {

	return 1;
}

int main() {

	int b;
	static int c;	// 지역변수면서 전역변수의 형태 (생성 다름)
	const int d = 10;
	char arr[20] = "hi";
	char* parr = "hong";

	printf("func: %p\n", &func);
	printf("global_a: %p\n", &a);
	printf("local b: %p\n", &b);
	printf("global_c: %p\n", &global_c);
	printf("static c: %p\n", &c);
	printf("const d: %p\n", &d);
	printf("array: %p\n", arr);
	printf("parr: %p\n", parr);

	return 0;
}

/*
	메모리구조
	data segment: stack, heap, data
	code segment: s
*/


/*
전역변수와 static 변수는 프로그램 종료까지 존재
지역변수는 함수 호출 시 생성, 종료 시 소멸
문자열 상수는 읽기 전용, 포인터가 가리키는 주소만 스택에 존재
*/