#include "Persoana.h"

Persoana::Persoana(std::string nume, std::string prenume)
{
	if (nume.empty() || prenume.empty())
		throw std::invalid_argument("Numele sau prenumele nu a fost specificat");
	this->nume = nume;
	this->prenume = prenume;
}

std::string Persoana::ToString(void)
{
	std::string identificare;
	identificare = "[" + this->nume + " " + this->prenume + "]";
	return identificare;
}

Student::Student(std::string nume, std::string prenume, int id, float medie) : Persoana(nume, prenume)
{
	if (id <= 0)
		throw std::invalid_argument("ID-ul trebuie sa fie > 0");
	if (medie <= 0)
		throw std::invalid_argument("Media trebuie sa fie > 0");
	this->id = id;
	this->medie = medie;
}

std::string Student::ToString(void)
{
	std::string identificare;
	identificare = "[" + std::to_string(this->id) + ". " + this->nume + " " + this->prenume
		+ " cu media " + std::to_string(this->medie) + "]";
	return identificare;
}

Profesor::Profesor(std::string nume, std::string prenume, std::string domeniu) : Persoana(nume, prenume)
{
	if (domeniu.empty())
		throw std::invalid_argument("Domeniul nu a fost specificat");
	this->domeniu = domeniu;
}

std::string Profesor::ToString(void)
{
	std::string identificare;
	identificare = "[" + this->nume + " " + this->prenume
		+ " preda " + this->domeniu + "]";
	return identificare;
}