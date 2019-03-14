#include <iostream>
#include "MeniuPrincipal.h"
#include "MeniuIntroducere.h"
#include "MeniuCautare.h"

void displayMP(void)
{
	std::cout << "\n"
		"Meniu Principal:\n"
		"1.Introducere date.\n"
		"2.Cautare date.\n"
		"3.Listare date.\n"
		"0.Iesire Aplicatie.\n"
		"\n";
}

void displayMI(void)
{
	std::cout << "\n"
		"Meniu Introducere Date:\n"
		"1.Despre studenti.\n"
		"2.Despre profesori.\n"
		"3.Revenire la meniul principal.\n"
		"\n";
}

void displayMC(void)
{
	std::cout << "\n"
		"Meniu Cautare Date:\n"
		"1.Despre studenti.\n"
		"2.Despre profesori.\n"
		"3.Revenire la meniul principal.\n"
		"\n";
}

void displayAll(void)
{
	// TO DO
}