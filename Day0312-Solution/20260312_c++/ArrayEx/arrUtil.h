#ifndef ARRUTIL_H
#define ARRUTIL_H

#include <iostream>
#include <iterator>
#include <random>
using namespace std;

template<typename T>
T getRandom(T min, T max) {
	// c++ 11 이상에서 사용 가능한 랜덤 생성기(성능이 좋음)
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<T> dist(min, max);

	return dist(gen);
}

// template이 들어간 header 파일은 반드시 template이 선언된 형태로 작성해야 한다.
template <typename T, size_t N> 
void printArr(T(&arr)[N]) {
	for (size_t i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// 배열의 크기를 지정해서 초기화하는 함수
template <size_t N>
//initArr → 함수
//(int(&arr)[N]) → 배열 참조를 받는다
//int(&)[N] → 배열 참조를 반환한다
int(&initArr(int(&arr)[N]))[N] {
	for (size_t i = 0; i < N; i++) {
		arr[i] = i;
	}
	return arr;
}

// 배열의 요소를 섞는 함수
template <size_t N>
//shuffleArr → 함수
//(int(&arr)[N]) → 배열 참조를 받는다
//int(&)[N] → 배열 참조를 반환한다
int(&shuffleArr(int(&arr)[N]))[N] {

	for (size_t i = 0; i < N - 1; i++) {
		//size_t j = rand() % (N - i) + i; // i부터 N-1 사이의 랜덤한 인덱스 선택
		size_t j = getRandom<size_t>(i, N - 1); // i부터 N-1 사이의 랜덤한 인덱스 선택
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	return arr;
}

// 배열을 선택 정렬하는 함수
template <size_t N>
int(&selectionSort(int(&arr)[N]))[N] {

	for (size_t i = 0; i < N - 1; i++) {

		size_t minIdx = i;

		for (size_t j = i + 1; j < N; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}

		if (minIdx != i) {
			int tmp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = tmp;
		}
	}

	return arr;
}

// 배열을 버블 정렬하는 함수
template <size_t N>
// bubbleSort → 함수
// (int(&arr)[N]) → 배열 참조를 받는다
// int(&)[N] → 배열 참조를 반환한다
int(&bubbleSort(int(&arr)[N]))[N] {
	for (size_t i = 0; i < N - 1; i++) {
		for (size_t j = 0; j < N - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return arr;
}



#endif
