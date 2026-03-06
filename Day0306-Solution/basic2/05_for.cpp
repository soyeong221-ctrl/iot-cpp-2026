// for문 - 구구단

#include <iostream>
#include <iomanip>
using namespace std;

/*
int main() {
	
	int n;

	cout << "몇 단을 출력하시겠습니까? "; 
	cin >> n;
	*/

	/*
	for (int i = 2; i < 10; i += 3) {
	
		for (int j = 1; j < 10; j++) {
		
			for (int k = 0; k < 3; k++) {
			
				if (i + k != 10) {
					cout << (i + k) << "*" << j << "=" << setw(2) << setfill(' ') << j * (i + k) << "\t";
				}
			}
			cout << endl;
		}
		cout << "\n";
	}


	for (int n = 2; n <= 9; n++) {							// 2단~9단 반복
		cout << "\n= " << n << "단 =" << endl;

		for (int i = 1; i <= 9; i++) {						// i는 지역변수. for문의 끝나면 사라짐.
			cout << n << "x" << i << "=" << n * i << endl;
		}
	}

	return 0;
}

*/