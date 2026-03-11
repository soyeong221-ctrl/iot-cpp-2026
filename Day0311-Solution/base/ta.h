#ifndef TA_H
#define TA_H
#include "student.h"
#include "professor.h"

class Ta : public Professor, public Student {
public:
	Ta(string name, double gpa, double salary);
	~Ta();
	void print();

};

#endif

// ctrl K + D : 자동정렬