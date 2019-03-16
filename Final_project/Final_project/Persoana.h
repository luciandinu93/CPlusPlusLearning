#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>
#include <stdexcept>

class Persoana
{
public:
	Persoana();
	Persoana(std::string nume, std::string prenume);
	virtual std::string ToString(void);
	virtual std::string getFileName(void);
protected:
	std::string nume;
	std::string prenume;
};

class Student : public Persoana
{
public:
	Student();
	Student(std::string nume, std::string prenume, int id, float medie);
	std::string ToString(void);
	std::string getFileName(void);
private:
	int id;
	float medie;
};

class Profesor : public Persoana
{
public:
	Profesor();
	Profesor(std::string nume, std::string prenume, std::string domeniu);
	std::string ToString(void);
	std::string getFileName(void);
private:
	std::string domeniu;
};

#endif // PERSOANA_H