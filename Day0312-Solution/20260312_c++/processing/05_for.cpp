#include <iostream>
#include <iomanip>

using namespace std;
int main() {
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++) {
			cout << i << "*" << j << "=" << i * j << endl;
		}
		cout << "\n";
	}
	for (int i = 2; i < 10; i+=3)
	{
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < 3; k++)
			{
				if (i + k != 10) {
					cout << (i + k) << "*" << j << "=" << setw(2) << setfill(' ') << j * (i + k) << "\t";
				}
			}
			cout << endl;
		}
		cout << "\n";
	}

	int num;
	int total = 0;
	// 숫자만 입력이 끝날 때까지 반복 (EOF)
	while (cin >> num) { total += num; }
	cout << "총합: " << total << endl;
	return 0;

}
