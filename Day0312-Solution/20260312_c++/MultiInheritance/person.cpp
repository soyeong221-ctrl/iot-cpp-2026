#include "person.h"

Person::Person(string name)
	:name(name)
{

}
Person::~Person()
{
}
void Person::print()
{
	cout << "Person Name: " << name << endl;
}