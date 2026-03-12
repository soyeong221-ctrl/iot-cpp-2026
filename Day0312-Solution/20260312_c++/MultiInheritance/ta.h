#ifndef TA_H
#define TA_H
#include "student.h"
#include "professor.h"

class TA : public Professor, public Student {
public:
	TA(string name, double gpa, double salary);
	~TA();
	void print();
};
#endif