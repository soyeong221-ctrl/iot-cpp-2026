// while
// 내 마음의 숫자 게임
/*
1. 랜덤 숫자 생성(1~100)
2. input
3. 비교(number < or > input)
4. 결과 1)맞으면-exit 2) 크면-메시지 3) 작으면-메시지
5. 2번부터 다시 반복
6. do while문

*/

/*
#include <iostream>
#include <cstdlib>   // rand()
#include <ctime>     // time()

using namespace std;

int main() {
	
	srand(time(0));
	int num = rand() % 100 + 1;
	int input;
	
	// cout << num << endl;

	do {
		cout << "숫자 입력: ";
		cin >> input;

		if (input == num) {
			cout << "정답" << endl;
		}

		else if (input < num) {
			cout << "더 큰 숫자입니다." << endl;
		}

		else {
			cout << "더 작은 숫자입니다." << endl;
			break;	// break는 반복문만 빠져나감
		}

	} while (input != num); // 맞출 때까지 반복
	

	return 0;
}

*/