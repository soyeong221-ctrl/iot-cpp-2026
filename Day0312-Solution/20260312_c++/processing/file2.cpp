#include <iostream>
using namespace std;

extern int value;   // 접근 시도 error

int main() {
    cout << value << endl;
}
