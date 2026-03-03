// c 복습

#include <stdio.h>

int n = 3.14;	// 전역변수

int main() {
								// 지역변수
	char str[] = "hong";		// 캐릭터 배열 형태의 저장 
	char* str1 = "hong";		// 포인터 형태의 저장


	//printf("str : %s\n", str);

	//printf("str[0] : %c\n", str[0]);
	//printf("str[1] : %c\n", str[1]);
	//printf("str[2] : %c\n", str[2]);
	//printf("str[3] : %c\n", str[3]);
	//printf("str[4] : %c\n", str[4]);

	printf("str: %p\n", str);
	printf("str1: %p\n", &str1);
	printf("hong: %p\n", *str1);
	
	printf("n : %p\n", &n);

	return 0;
}