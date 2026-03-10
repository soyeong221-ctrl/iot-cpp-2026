// 상속관계

#include <iostream>
using namespace std;

/*

class Parent {
private:
	long id;
public:
	void setId(long id);
	long getId();
	Parent(long id);
	Parent();
}; 

Parent::Parent(long id) {
	if (id >= 100000L && id <= 999999L) {
		this->id = id;
	}
	else {
		this->id = 0L;
	}
}

void Parent::setId(long id) {
	this->id = id;
}

long Parent::getId() {
	return id;
}


class Child : public Parent {
private: 
	double tech_level;
public: 
	void setTechLevel1(double tech_level);
	double getTechLevel();
	Child(long id, double tech_level);
	Child();
};

Child::Child() : Parent(0l), tech_level(0.0) {}

Child::Child(long id, double tech_level) : Parent(id) {
	this->tech_level = tech_level;
}

void Child::setTechLevel1(double tech_level) {
	this->tech_level = tech_level;
}

double Child::getTechLevel() {
	return tech_level;
}


int main() {

	//Parent p(111111);

	Child c(100000l, 2.0);
	cout << "Child의 id: " << c.getId() << endl;	// 실행할 때는 -> 함수명();
	cout << "Child의 기술 수준: " << c.getTechLevel() << endl;
}

*/

