#include "PersonHandling.h"
#include "FileHandling.h"

bool isNum(std::string number)
{
	int point_k = 0;

	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] == '.')
			point_k++;
		else if (number[i] < '0' || number[i] > '9')
			return false;
		if (point_k > 1)
			return false;
	}

	return true;
}

int findStudentById(int id)
{
	int studenti_nr = getStudentiNr();
	int* studenti_id = getStudentiId();
	for (int i = 0; i < studenti_nr; i++)
	{
		if (studenti_id[i] == id)
			return i;
	}

	return -1;
}

Student createStudent(void)
{
	int id_num;
	std::string id, nume, prenume, medie;
	float medie_num;

	try
	{
		std::cout << "Introduceti id-ul studentului: ";
		std::getline(std::cin, id);
		if (isNum(id))
			id_num = atoi(id.c_str());
		else
			throw "ID-ul introdus nu reprezinta un numar!";

		while (findStudentById(id_num) != -1)
		{
			std::cout << "Acest ID exista deja, va rog alegeti alt ID";
			if (isNum(id))
				id_num = atoi(id.c_str());
			else
				throw "ID-ul introdus nu reprezinta un numar!";
		}

		std::cout << "Introduceti numele studentului: ";
		std::getline(std::cin, nume);

		std::cout << "Introduceti prenumele studentului: ";
		std::getline(std::cin, prenume);

		std::cout << "Introduceti media studentului: ";
		std::getline(std::cin, medie);
		if (isNum(medie))
			medie_num = std::strtof(medie.c_str(), 0);
		else
			throw "Media introdusa nu reprezinta un numar!";
		Student student(nume, prenume, id_num, medie_num);

		return student;
	}
	catch (std::exception& e)
	{
		std::cout << "Nu pot crea studentul deoarece, " << e.what() << std::endl;
	}
}