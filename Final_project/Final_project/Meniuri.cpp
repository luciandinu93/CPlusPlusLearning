#include <iostream>
#include "MeniuPrincipal.h"
#include "MeniuIntroducere.h"
#include "MeniuCautare.h"
#include "FileHandling.h"
#include "PersonHandling.h"

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

void introducereStudenti(Student*& studenti)
{
	int nr_persoane;
	std::string comanda_str;
	std::cin.ignore();
	do
	{
		try
		{
			nr_persoane = getPersoaneNr(STUDENTI_FILE);
			if (!nr_persoane)
			{
				std::cout << "\n - Nu exista niciun student! - \n" << std::endl;
				std::cout << "\nDoriti sa introduceti un nou student(d / n) ? " << std::endl;
				std::getline(std::cin, comanda_str);
				std::cout << "Comanda introdusa -" << comanda_str << "-" << std::endl;

				if (comanda_str == "d")
				{
					allocateMemForStudent(studenti, 0, 1);
					studenti[0] = createStudent();
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu :";
			}
			else
			{
				std::cout << "\nExista " << nr_persoane << " studenti." << "\n";
				allocateMemForStudent(studenti, nr_persoane, 1); // create studenti[0]
				loadPersoaneArray(studenti, nr_persoane);
				displayStudents(studenti, nr_persoane);
				std::cout << "\nDoriti sa introduceti un nou student (d/n)?";
				std::getline(std::cin, comanda_str);
				if (comanda_str == "d")
				{
					allocateMemForStudent(studenti, nr_persoane, 1); // TO DO
					studenti[nr_persoane] = createStudent();
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu" << std::endl;
			}
		}
		catch (const char* e)
		{
			std::cout << "ERROARE: la creeare student:" << e << std::endl;
		}
	} while (comanda_str != "n");
}

/*
void introducereProfesori(Profesor*& profesori)
{
	int nr_profesori;
	std::string comanda_str;
	std::cin.ignore();
	do
	{
		try
		{
			nr_profesori = getProfesoriNr();
			loadStudentiArray(profesori, nr_profesori);
			displayStudents(profesori, nr_profesori);
			if (!nr_profesori)
			{
				std::cout << "\n - Nu exista niciun student! - \n" << std::endl;
				std::cout << "\nDoriti sa introduceti un nou student(d / n) ? " << std::endl;
				std::getline(std::cin, comanda_str);
				std::cout << "Comanda introdusa -" << comanda_str << "-" << std::endl;

				if (comanda_str == "d")
				{
					allocateMemForStudent(profesori, 0, 1);
					profesori[0] = createProfesor();
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu :";
			}
			else
			{
				std::cout << "\nExista " << nr_profesori << " studenti." << "\n";
				std::cout << "\nDoriti sa introduceti un nou student (d/n)?";
				std::getline(std::cin, comanda_str);
				if (comanda_str == "d")
				{
					allocateMemForStudent(profesori, nr_profesori, 1); // TO DO
					profesori[nr_profesori] = createProfesor();
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu" << std::endl;
			}
		}
		catch (const char* e)
		{
			std::cout << "ERROARE: la creeare student:" << e << std::endl;
		}
	} while (comanda_str != "n");
}
*/


void processInputComand(Student*& studenti, Profesor*& profesori)
{
	int comanda = 0;
	int nr_studenti;
	int profesori_nr;
	std::string comanda_str;

	do
	{
		displayMI();

		std::cout << "Alegeti o optiune: ";
		std::cin >> comanda;

		switch (comanda)
		{
		case 1:
			introducereStudenti(studenti);
			break;
		case 2:
			//introducereProfesori(profesori);
			break;
		case 3:
			break;
		default:
			std::cout << "Va rog alegeti comanda 1, 2 sau 3 pentru revenire" << 
				" la meniul anterior." << std::endl;
			break;
		}
	} while (comanda != 3);
}