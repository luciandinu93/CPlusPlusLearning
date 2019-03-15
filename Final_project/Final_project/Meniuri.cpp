#include <iostream>
#include "MeniuPrincipal.h"
#include "MeniuIntroducere.h"
#include "MeniuCautare.h"
#include "FileHandling.h"

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
			do
			{
				try
				{
					nr_studenti = getStudentiNr();
					if (!nr_studenti)
					{
						std::cin.ignore();
						do
						{
							std::cout << "Nu exista niciun student!" << std::endl;
							std::cout << "Doriti sa introduceti un nou student(d / n) ? " << std::endl;
							std::getline(std::cin, comanda_str);
							std::cout << "Comanda introdusa -" << comanda_str << "-" << std::endl;
							if (comanda_str == "d")
								studenti[0] = createStudent();
							else if (comanda_str != "n")
								std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu" << std::endl;
						} while (comanda_str != "n");
					}
					else
					{
						std::cout << "Doriti sa introduceti un nou student (d/n)?";
						std::getline(std::cin, comanda_str);
						if (comanda_str == "d")
							studenti[nr_studenti] = createStudent();
						else if (comanda_str != "n")
							std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu" << std::endl;
					}
				}
				catch (const char* e)
				{
					std::cerr << e << std::endl;
				}
			} while (comanda_str != "n");
			//studenti[0] = addStudent(); // TO DO
			break;
		case 2:
			//addProfesor(); // TO DO
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