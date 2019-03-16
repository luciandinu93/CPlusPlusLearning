#pragma once
#include <iostream>
#include <string>
#include "Persoana.h"

Student createStudent(void);
bool isNum(std::string);
void allocateMemForStudent(Student*&, int, int);
void allocatedFixMem(Persoana*&, int);
void StudentToFile(Student, std::string);
void loadStudentiArray(Student*&, int);
void loadPersoaneArray(Persoana*, int); // test
void displayPersoane(Persoana*, int);
void displayStudents(Student*, int);
void displayProfesori(Profesor*, int);