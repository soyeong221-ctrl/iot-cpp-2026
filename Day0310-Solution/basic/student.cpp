#include "student.h"

Student::Student() 
	: Person(), gpa(0.0) {

}

Student::Student(long id, double g)
	: Person(id), gpa(g)
{
	assert(gpa >= 0.0 && gpa <= 4.0);
}

Student::Student(const Student& student)
	: Person(student), gpa(student.gpa){
}

Student::~Student() {
}

void Student::print() const {

	Person::print();
	cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
}