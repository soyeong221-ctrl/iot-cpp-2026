#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

class Person {
private: 
	long identity;
public:
	Person();
	Person(long identity);
	~Person();
	Person(const Person& other);
	void print() const;
};

#endif