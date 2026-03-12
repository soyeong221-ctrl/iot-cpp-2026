#ifndef REGISTRAR_H
#define REGISTRAR_H
#include "course.h"
#include "student2.h"

// 클래스 정의
class Registrar
{
public:
    Registrar();
    ~Registrar();
    void enroll(Student student, Course course);
};
#endif