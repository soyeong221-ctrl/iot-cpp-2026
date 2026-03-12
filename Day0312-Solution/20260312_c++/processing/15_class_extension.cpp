#include <iostream>
using namespace std;

class Parent {
private:
	long id;
public:
	void setId(long id);
	long getId() {
		return id;
	}
	Parent(long id);
};

Parent::Parent(long id) {
	if (id >= 100000L && id <= 999999L) {
		this->id = id;
	}
	//else {
	//	this->id = 0L;
	//}
}

void Parent::setId(long id) {
	this->id = id;
}

class Child : public Parent {
private:
	double tech_level;
public:
	void setTechLevel(double tech_level);
	double getTechLevel();
	Child(long id, double tech_level);
	Child();
};
Child::Child() : Parent(0l), tech_level(0.0) {}

Child::Child(long id, double tech_level) : Parent(id) {
	this->tech_level = tech_level;
}

void Child::setTechLevel(double tech_level) {
	this->tech_level = tech_level;
}
double Child::getTechLevel() {
	return tech_level;
}

int main() {
	Parent p(111111L);
	
	Child c(100000l, 2.0);
	//c.setId(222222l);
	cout << "Child의 id:" << c.getId() << endl;
	//cout << "child의 id:" << c.id << endl; // error: 'long Parent::id' is private within this context
	cout << "Child의 기술 수준:" << c.getTechLevel() << endl;

}