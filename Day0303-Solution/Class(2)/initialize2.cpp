#include <iostream>
using namespace std;

/*
class Time {
private:
	int m_hour;
	int m_min;
	int m_sec;
public:
	Time() {
		cout << "default constructor!!" << endl;
	}

	Time(int h, int m, int s) : m_hour(h), m_min(m), m_sec(s) {
		cout << "3 input constructor!!" << endl;

		//m_hour;
		//m_min;
		//m_sec;
	}

	void setTime(int h, int m, int s) {
		m_hour = h;
		m_min = m;
		m_sec = s;
	}
	void showTime() {
		printf("현재 시간은 %d시 %d분 %d초입니다.", m_hour, m_min, m_sec);
	}
};


int main() {

	//Time now;
	//now.setTime(16, 52, 30);
	//now.showTime();

	Time t1(16, 57, 33);
	t1.showTime();

	return 0;
}
*/


class constSome {		// 상수멤버일 때 초기화
public:
	const int value;
	constSome(int i) : value(i) {
	}

	void show() { printf("value: %d\n", value); }

};

class refSome {
public:
	int& ref;
	refSome(int& i) : ref(i) {}

	void show() { printf("ref: %d\n", ref); }
};

int main() {

	constSome cs(10);
	cs.show();
	
	int i = 5;
	refSome rs(i);
	rs.show();

	return 0;
}