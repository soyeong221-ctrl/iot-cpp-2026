#include "ta.h"

TA::TA(string name, double gpa, double salary)
	:Person(name), Student(name, gpa), Professor(name, salary)
{
}

TA::~TA() {
}

void TA::print() {
	cout << "Teaching Assistance Name: " << name << endl;
	cout << "GPA: " << gpa << endl;
	cout << "Salary: " << salary << endl;
}