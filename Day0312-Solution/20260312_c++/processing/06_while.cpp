#include <iostream>
#include <cstdlib>
#include < ctime>

using namespace std;
int main() {
	srand(time(0));
	cout << showpoint << rand() % 100 + 1 << endl;
	int num = rand() % 100 + 1;
	cout << num << endl;
    int guess = 0;
    int count = 0;

    cout << "=== 내 마음의 숫자를 맞춰 봐 게임 ===" << endl;
    cout << "1부터 100 사이의 숫자를 입력하세요." << endl;

    while (true) {
        cout << "숫자 입력 : ";
        cin >> guess;
        count++;

        if (guess < num) {
            cout << "UP! 더 큰 숫자입니다." << endl;
        }
        else if (guess > num) {
            cout << "DOWN! 더 작은 숫자입니다." << endl;
        }
        else {
            cout << "정답입니다!" << endl;
            cout << count << "번 만에 맞췄습니다." << endl;
            break;
        }
    }

    return 0;
}