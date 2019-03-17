#include "PersonHandling.h"
#include "FileHandling.h"

void displayPersoane(Persoana* persoane, int nr_persoane)
{
	std::cout << "\n************************************\n";
	for (int i = 0; i < nr_persoane; i++)
	{
		std::cout << persoane[i].ToString() << std::endl;
	}
	std::cout << "************************************\n";
}

void displayProfesori(Profesor* profesori, int nr_profesori)
{
	std::cout << "\n************************************\n";
	for (int i = 0; i < nr_profesori; i++)
	{
		std::cout << profesori[i].ToString() << std::endl;
	}
	std::cout << "************************************\n";
}

void displayStudents(Student* studenti, int nr_studenti)
{
	std::cout << "\n************************************\n";
	for (int i = 0; i < nr_studenti; i++)
	{
		std::cout << studenti[i].ToString() << std::endl;
	}
	std::cout << "************************************\n";
}

void loadStudentiArray(Student*& studenti, int nr_studenti)
{
	int id_num, studenti_nr, i = 0;
	float medie_num;
	std::string id, nume, prenume, medie;

	studenti = new Student[nr_studenti];

	std::ifstream file;
	std::string line;

	file.open(STUDENTI_FILE);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			try
			{
				std::istringstream ss(line);
				ss >> id >> nume >> prenume >> medie;
				id = id.substr(1); // remove '[' char from beginning
				// Debug only
				// std::cout << "id:." << id << "." << std::endl;
				if (isNum(id))
					id_num = atoi(id.c_str());
				else
					throw "ID-ul introdus nu reprezinta un numar!";

				medie = medie.substr(0, medie.find('.') + 2);
				if (isNum(medie))
					medie_num = std::strtof(medie.c_str(), 0);
				else
					throw "Media introdusa nu reprezinta un numar!";

				// Degub only
				//std::cout << "Acum incerc sa creez urmatorul student " <<
				//	"." << id_num << "." << nume << "." << prenume << "." << medie_num << ".\n";
				studenti[i] = Student(nume, prenume, id_num, medie_num);
				i++;
				ss.ignore();
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		file.close();
	}
	else
	{
		throw "Could not open/read/close the file " + std::string(STUDENTI_FILE);
	}
}

void loadProfesoriArray(Profesor*& profesori, int nr_profesori)
{
	int i = 0;
	std::string nume, prenume, domeniu;

	profesori = new Profesor[nr_profesori];

	std::ifstream file;
	std::string line;
	std::string temp;

	file.open(PROFESORI_FILE);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			try
			{
				std::istringstream ss(line);
				ss >> nume >> prenume >> domeniu;
				
				while (ss >> temp)
				{
					ss >> temp;
					domeniu = domeniu + " " + temp;
				}
					
				// modify strings
				nume = nume.substr(1);
				domeniu = domeniu.substr(0, domeniu.length() - 1);
				profesori[i] = Profesor(nume, prenume, domeniu);
				i++;
				ss.ignore();
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		file.close();
	}
	else
	{
		throw "Could not open/read/close the file " + std::string(PROFESORI_FILE);
	}
}

void allocateMemForProfesor(Profesor*& profesori, int nr_profesori, int nr_to_add)
{

	int new_size;
	if (!nr_profesori)
	{
		profesori = new Profesor();
	}
	else
	{
		new_size = nr_profesori + nr_to_add;
		Profesor* temp_arr = new Profesor[new_size];

		// muta studentii in noul array temporar
		for (int i = 0; i < nr_profesori; i++)
		{
			temp_arr[i] = profesori[i];
		}

		// mareste array-ul studenti
		profesori = new Profesor[new_size];

		// muta inapoi studentii in array-ul initial
		for (int i = 0; i < nr_profesori; i++)
		{
			profesori[i] = temp_arr[i];
		}

		// sterge array-ul temporar pentru a elibera memoria
		delete[] temp_arr;

		// evita pointer saltaret ( asignare pointer NULL)
		temp_arr = NULL;
	}
}

void allocateMemForStudent(Student*& studenti, int nr_studenti, int nr_to_add)
{
	
	int new_size;
	if (!nr_studenti)
	{
		studenti = new Student();
	}
	else
	{
		new_size = nr_studenti + nr_to_add;
		Student* temp_arr = new Student[new_size];

		// muta studentii in noul array temporar
		for (int i = 0; i < nr_studenti; i++)
		{
			temp_arr[i] = studenti[i];
		}

		// mareste array-ul studenti
		studenti = new Student[new_size];

		// muta inapoi studentii in array-ul initial
		for (int i = 0; i < nr_studenti; i++)
		{
			studenti[i] = temp_arr[i];
		}

		// sterge array-ul temporar pentru a elibera memoria
		delete[] temp_arr;

		// evita pointer saltaret ( asignare pointer NULL)
		temp_arr = NULL;
	}
}

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

bool isIDNum(std::string number)
{
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return false;
	}

	return true;
}

int findStudentById(int id)
{
	int studenti_nr = getPersoaneNr(STUDENTI_FILE);
	int* studenti_id = getStudentiId();
	for (int i = 0; i < studenti_nr; i++)
	{
		if (studenti_id[i] == id)
			return i;
	}

	return -1;
}

int findProfesorByNume(std::string nume, int index)
{
	to_lower(nume);
	int profesori_nr = getPersoaneNr(PROFESORI_FILE);
	std::string* profesori_names = new std::string[profesori_nr];
	profesori_names = getProfesoriNames(index);
	for (int i = 0; i < profesori_nr; i++)
	{
		if (profesori_names[i].find(nume) != std::string::npos)
		{
			delete[] profesori_names;
			return i;
		}
	}

	delete[] profesori_names;
	return -1;
}

void StudentToFile(Student student, std::string file_location)
{
	std::ofstream out;

	out.open(file_location, std::ios::app);
	if (out.is_open())
	{
		out << student.ToString();
		out << "\n";

		out.close();
	}
	else
	{
		throw "Can not open\read\close the " + std::string(STUDENTI_FILE) + " file";
	}
}

void ProfesorToFile(Profesor profesor, std::string file_location)
{
	std::ofstream out;

	out.open(file_location, std::ios::app);
	if (out.is_open())
	{
		out << profesor.ToString();
		out << "\n";

		out.close();
	}
	else
	{
		throw "Can not open\read\close the " + std::string(PROFESORI_FILE) + " file";
	}
}

Student createStudent(void)
{
	int id_num;
	std::string id, nume, prenume, medie;
	float medie_num;
	Student student;

	try
	{
		std::cout << "Introduceti id-ul studentului: ";
		std::getline(std::cin, id);
		if (isIDNum(id))
			id_num = atoi(id.c_str());
		else
			throw "ID-ul introdus nu reprezinta un numar!";
		if(findStudentById(id_num) != -1)
			throw "Acest ID exista deja, va rog alegeti alt ID!";

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
	}
	catch (std::exception& e)
	{
		std::cout << "Nu pot crea studentul deoarece, " << e.what() << std::endl;
	}

	// Try to create a student
	try
	{
		Student student(nume, prenume, id_num, medie_num);

		// Add student to file
		StudentToFile(student, STUDENTI_FILE);

		return student;
	}
	catch (const std::exception& e)
	{
		std::cout << "Nu pot crea studentul deoarece ," << e.what() << std::endl;
	}

	return student;
}

Profesor createProfesor(void)
{
	std::string nume, prenume, domeniu;
	Profesor profesor;

	try
	{
		std::cout << "Introduceti numele profesorului: ";
		std::getline(std::cin, nume);

		std::cout << "Introduceti prenumele profesorului: ";
		std::getline(std::cin, prenume);

		std::cout << "Introduceti domeniul profesorului: ";
		std::getline(std::cin, domeniu);
	}
	catch (std::exception& e)
	{
		std::cout << "Nu pot crea profesorul deoarece, " << e.what() << std::endl;
	}

	// Try to create a profesor
	try
	{
		Profesor profesor(nume, prenume, domeniu);

		// Add student to file
		ProfesorToFile(profesor, PROFESORI_FILE);

		return profesor;
	}
	catch (const std::exception& e)
	{
		std::cout << "Nu pot crea studentul deoarece ," << e.what() << std::endl;
	}

	return profesor;
}