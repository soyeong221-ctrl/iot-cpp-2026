#include "register.h"

// 생성자
Registrar::Registrar()
{
}
// 소멸자
Registrar::~Registrar()
{
}
// enroll 함수
void Registrar::enroll(Student student, Course course)
{
	(course.getRoster())->addStudent(student.getName());
	(student.getSchedule())->addCourse(course.getName());
}