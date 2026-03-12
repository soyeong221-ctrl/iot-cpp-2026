#include <iostream>
using namespace std;

int main() {
    int month;

    cout << "월 입력 (1~12) : ";
    cin >> month;

    // if 문
    if (month >= 3 && month <= 5)
        cout << "봄입니다." << endl;
    else if (month >= 6 && month <= 8)
        cout << "여름입니다." << endl;
    else if (month >= 9 && month <= 11)
        cout << "가을입니다." << endl;
    else if (month == 12 || month == 1 || month == 2)
        cout << "겨울입니다." << endl;
    else
        cout << "잘못된 월입니다." << endl;

    // switch case 문
    switch (month) {
    case 3:     case 4:    case 5:
        cout << "봄입니다." << endl;
        break;

    case 6:    case 7:    case 8:
        cout << "여름입니다." << endl;
        break;

    case 9:    case 10:    case 11:
        cout << "가을입니다." << endl;
        break;

    case 12:   case 1:    case 2:
        cout << "겨울입니다." << endl;
        break;

    default:
        cout << "잘못된 월입니다." << endl;
    }
    return 0;

}
