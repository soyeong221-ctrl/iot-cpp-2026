#include "ta.h"

Ta::Ta(string name, double gpa, double salary)
	:Person(name), Student(name, gpa), Professor(name, salary){

}

Ta::~Ta() {

}

void Ta::print() {
	cout << "Teaching Assistance Name: " << name << endl;
	cout << "GPA: " << gpa << endl;
	cout << "Salary: " << salary << endl;
}