#include <iostream>
#include <string>
using namespace std;
class Product {
private:
	int price;
	string name;
public:
	Product(int p, string n) : price(p), name(n) {}
	int getPrice() const { return price; }
};

class Tv : public Product  {
public:
    Tv();
};
Tv::Tv() : Product(300, "TV") {}

class Computer : public Product {
public:
    Computer() :Product(300, "Computer") {}
};

class Audio : public Product {
public:
    Audio() :Product(400, "Audio") {}
};

class Customer {
private:
	int money = 1000; // Customer has 1000 units of money
public:
	// 1. Method overloading 제품마다 buy 함수를 만들어야 하는 경우
    //void buy(Tv tv) {money -= tv.price; }
    //void buy(Audio audio) {money -= audio.price; }
    //void buy(Computer com) {money -= com.price;}

	// 2. Template function을 이용한 방법
	//template<typename T>
    //void buy(T item) {money -= item.price; }

	// 3. 상속의 Polymorphism을 이용한 방법
    void buy(Product& product) {
        // Assuming we have a way to get the price from the Product class
        money -= product.getPrice();
	}
    void showMoney() const {
        cout << "Remaining money: " << money << endl;
	}
};

int main() {
    Customer customer;
    Tv tv;
    Computer com;
    Audio audio;


    // Typecasting
    customer.buy(tv);
    customer.buy(audio);
    customer.buy(com);
	customer.showMoney(); 
    return 0;
}