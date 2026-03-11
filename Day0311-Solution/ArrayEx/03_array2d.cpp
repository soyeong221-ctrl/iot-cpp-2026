#include <iostream>
#include <iomanip>
#include "arrutil.h"
using namespace std;

int main() {

	int arr[] = { 1, 2, 3, 4, 5 };
	int sum = 0;
	for (int i = 0; i < size(arr); i++) {
		sum += arr[i];   // sum = sum + arr[i]
	}

	cout << "sum: " << sum << endl;
	cout << "avg: " << static_cast<double>(sum) / size(arr) << endl;

	int arr2[3][4]{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	printArr(arr2);

	for (int i = 0; i < size(arr2); i++) {
		for (int j = 0; j < size(arr2[i]); j++) {
			cout << setw(2) << arr2[i][j] << " ";
		}
		cout << endl;
	}
	int tmp[4][5];
	memset(tmp, 0, sizeof(tmp)); // tmp 배열을 0으로 초기화

	for (int i = 0; i < size(arr2); i++) {
		for (int j = 0; j < size(arr2[i]); j++) {
			tmp[i][j] = arr2[i][j];
			tmp[size(arr2)][j] += arr2[i][j];
			tmp[j][size(arr2[i])] += arr2[i][j];
			//tmp[size(arr2)][size(arr2[i])] += arr2[i][j];
			cout << setw(2) << (arr2[i][j]) << " ";

		}
		cout << endl;
	}
	for (int i = 0; i < size(tmp); i++) {
		for (int j = 0; j < size(tmp[i]); j++) {
			cout << setw(2) << (tmp[i][j]) << " ";
		}
		cout << endl;
	}

	return 0;
}