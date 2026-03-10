// 클래스. 1000불을 받아서 마트 가서 전자용품을 살 예정. ! 형변환 사용
// 클래스 4개 만들기. customer, 티비(300불), 오디오(400불), 컴퓨터(300불) - 전자기기는 가격 필요.

/*
#include <iostream>
using namespace std;

class Product {
private:
	int price;
	string name;

public:
	Product(int p, string n) : price(p), name(n) {}
	int getPrice() const {
		return price;
	}
};


class Tv : public Product {
public:
	Tv() : Product(300, "TV") {}
};

// 또 다른 샘플
// public:
//	TV();
// };
// Tv::Tv() : Product(300, "TV") {}

class Computer : public Product {
public:
	Computer() : Product(300, "Computer") {}
};

class Audio : public Product {
public:
	Audio() : Product(400, "Audio") {}
};

class Customer {
private:
	int money = 1000;	// Customer has 1000 units of money
public:
	// 1. 오버로딩: 제품마다 buy 함수를 만들어야 하는 경우
	//void buy(Tv tv) {money -= tv.price; // 고객이 가진 돈에서 TV 가격만큼 빼라.}
	//void buy(Audio audio) {money -= audio.price; // 고객이 가진 돈에서 Audio 가격만큼 빼라.}
	//void buy(Computer com) {money -= com.price; // 고객이 가진 돈에서 Computer 가격만큼 빼라.}

	// 2. Template function을 이용한 방법
	//template<typename T>
	//void buy(T item) {money -= item.price;}

	// 3. 상속의 초기화를 이용한 방법
	void buy(Product& product) {
		money -= product.getPrice();
	}
	void showMoney() const {
		cout << " 남은 돈: " << money << endl;
	}

};


int main(){
	Customer customer;
	Tv tv;
	Computer com;
	Audio audio;

	//Typecasting
	customer.buy(tv);
	customer.buy(audio);
	customer.buy(com);
	customer.showMoney();

	return 0;
}
*/