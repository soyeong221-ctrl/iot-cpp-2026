#include <iostream>
#include "arrUtil.h"
using namespace std;

int main() {
	int arr1[] = { 1, 2, 3, 4, 5 };
	string arr2[] = { "Hello", "World", "C++" };
	char arr3[] = { 'A', 'B', 'C', 'D', 48 };
	printArr(arr1);
	printArr(arr2);
	printArr(arr3);

	int arr4[10];
	initArr(arr4);
	printArr(arr4);

	shuffleArr(arr4);
	printArr(arr4);

	selectionSort(arr4);
	printArr(arr4);

	//C++에서는 배열 참조 반환 덕분에 함수 체이닝이 가능
	printArr(shuffleArr(arr4));
	printArr(bubbleSort(arr4));

	return 0;
}