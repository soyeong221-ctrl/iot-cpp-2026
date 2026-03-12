#include "ta.h"

int main() {
	TA ta("Alice", 3.8, 15000);
	ta.print();

	Student* studentPtr = &ta;
	studentPtr->print();

	Professor* professorPtr = &ta;
	professorPtr->print();

	Person* personPtr = &ta;
	personPtr->print();

	return 0;
}
