#pragma once
#include <iostream>
#include <string>
#include "Persoana.h"

Student createStudent(void);
Profesor createProfesor(void);
bool isNum(std::string);
bool isIDNum(std::string);
void allocateMemForStudent(Student*&, int, int);
void allocateMemForProfesor(Profesor*&, int, int);
void StudentToFile(Student, std::string);
void ProfesorToFile(Profesor, std::string);
void loadStudentiArray(Student*&, int);
void loadProfesoriArray(Profesor*&, int);
void displayPersoane(Persoana*, int);
void displayStudents(Student*, int);
void displayProfesori(Profesor*, int);
int findStudentById(int id);
int findProfesorByNume(std::string, int);