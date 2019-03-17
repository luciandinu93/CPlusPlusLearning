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

void displayAll(Student*& studenti, Profesor*& profesori)
{
	int nr_studenti, nr_profesori;
	nr_studenti = getPersoaneNr(STUDENTI_FILE);
	nr_profesori = getPersoaneNr(PROFESORI_FILE);

	if (nr_studenti == 0)
	{
		std::cout << "\n - Nu exista niciun student! - \n" << std::endl;
	}
	else
	{	std::cout << "Studenti: " << std::endl;
		loadStudentiArray(studenti, nr_studenti);
		displayStudents(studenti, nr_studenti);
	}

	std::cout << "\n------------------------------------------------\n";

	if (nr_profesori == 0)
	{
		std::cout << "\n - Nu exista niciun profesor! - \n" << std::endl;
	}
	else
	{
		std::cout << "Profesori:" << std::endl;
		loadProfesoriArray(profesori, nr_profesori);
		displayProfesori(profesori, nr_profesori);
	}

	std::cout << std::endl;
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
				to_lower(comanda_str);
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
				loadStudentiArray(studenti, nr_persoane);
				displayStudents(studenti, nr_persoane);
				std::cout << "\nDoriti sa introduceti un nou student (d/n)?";
				std::getline(std::cin, comanda_str);
				to_lower(comanda_str);
				if (comanda_str == "d")
				{
					allocateMemForStudent(studenti, nr_persoane, 1); // TO DO
					studenti[nr_persoane] = createStudent();
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cout << "ERROARE: la creeare student:" << e.what() << std::endl;
			break;
		}
	} while (comanda_str != "n");
}

void introducereProfesori(Profesor*& profesori)
{
	int nr_persoane;
	std::string comanda_str;
	std::cin.ignore();
	do
	{
		try
		{
			nr_persoane = getPersoaneNr(PROFESORI_FILE);
			if (!nr_persoane)
			{
				std::cout << "\n - Nu exista niciun profesor! - \n" << std::endl;
				std::cout << "\nDoriti sa introduceti un nou profesor(d / n) ? " << std::endl;
				std::getline(std::cin, comanda_str);
				to_lower(comanda_str);
				if (comanda_str == "d")
				{
					allocateMemForProfesor(profesori, 0, 1);
					profesori[0] = createProfesor();
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu :";
			}
			else
			{
				std::cout << "\nExista " << nr_persoane << " profesori." << "\n";
				loadProfesoriArray(profesori, nr_persoane);
				displayProfesori(profesori, nr_persoane);
				std::cout << "\nDoriti sa introduceti un nou profesor (d/n)?";
				std::getline(std::cin, comanda_str);
				to_lower(comanda_str);
				if (comanda_str == "d")
				{
					allocateMemForProfesor(profesori, nr_persoane, 1); // TO DO
					profesori[nr_persoane] = createProfesor();
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cout << "ERROARE: la creeare profesor:" << e.what() << std::endl;
			break;
		}
	} while (comanda_str != "n");
}

void cautareStudenti(Student*& studenti)
{
	int nr_persoane, id_num, index;
	std::string comanda_str, id_str;
	std::cin.ignore();
	do
	{
		try
		{
			nr_persoane = getPersoaneNr(STUDENTI_FILE);
			if (!nr_persoane)
			{
				std::cout << "\n - Nu exista niciun student! - \n" << std::endl;
				break;
			}
			else
			{
				std::cout << "\nExista " << nr_persoane << " studenti." << "\n";
				loadStudentiArray(studenti, nr_persoane);

				std::cout << "\nDoriti sa cautati un student dupa id(d / n) ? " << std::endl;
				std::getline(std::cin, comanda_str);
				to_lower(comanda_str);

				if (comanda_str == "d")
				{
					std::cout << "\nIntroduceti ID-ul studentului cautat: ";
					std::getline(std::cin, id_str);

					if (isIDNum(id_str))
					{
						id_num = atoi(id_str.c_str()); // casting from string to int
						index = findStudentById(id_num);
						if (index == -1)
						{
							std::cout << "Studentul cu id-ul " << id_num << " nu exista in fisier.";
						}
						else
						{
							std::cout << "Studentul cautat este: " << studenti[index].ToString() << std::endl;
						}
					}
					else
					{
						throw std::invalid_argument("ID-ul nu reprezinta un numar!");
					}
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu :";
			}
		}
		catch (std::exception& e)
		{
			std::cout << "ERROARE: la cautare student:" << e.what() << std::endl;
			break;
		}
	} while (comanda_str != "n");
}

void cautareProfesori(Profesor*& profesori)
{
	int nr_persoane, index = 0, found_profesori = 0;
	std::string comanda_str, nume;
	std::cin.ignore();
	do
	{
		try
		{
			nr_persoane = getPersoaneNr(PROFESORI_FILE);
			if (!nr_persoane)
			{
				std::cout << "\n - Nu exista niciun profesor! - \n" << std::endl;
				break;
			}
			else
			{
				std::cout << "\nExista " << nr_persoane << " profesori." << "\n";
				loadProfesoriArray(profesori, nr_persoane);

				std::cout << "\nDoriti sa cautati un profesor dupa nume(d / n) ? " << std::endl;
				std::getline(std::cin, comanda_str);
				to_lower(comanda_str);

				if (comanda_str == "d")
				{
					std::cout << "\nIntroduceti numele profesorului cautat: ";
					std::getline(std::cin, nume);

					loadProfesoriArray(profesori, nr_persoane);

					while (index != -1)
					{
						index = findProfesorByNume(nume, index);
						if (index != -1)
						{
							found_profesori++;
							std::cout << "Profesorul cautat este: " << profesori[index].ToString() << std::endl;
						}
							
					}
					
					if (found_profesori == 0)
					{
						std::cout << "Profesorul cu numele " << nume << " nu exista in fisier.";
					}
				}
				else if (comanda_str != "n")
					std::cout << "Comanda nu exista va rog introduceti d - da sau n - nu :";
			}
		}
		catch (std::exception& e)
		{
			std::cout << "ERROARE: la cautare student:" << e.what() << std::endl;
			break;
		}
	} while (comanda_str != "n");
}

void processInputComand(Student*& studenti, Profesor*& profesori)
{
	int comanda = 0;
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
			introducereProfesori(profesori);
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

void processFindComand(Student*& studenti, Profesor*& profesori)
{
	int comanda = 0;
	std::string comanda_str;

	do
	{
		displayMC();

		std::cout << "Alegeti o optiune: ";
		std::cin >> comanda;

		switch (comanda)
		{
		case 1:
			cautareStudenti(studenti);
			break;
		case 2:
			cautareProfesori(profesori);
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