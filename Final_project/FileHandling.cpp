#include "FileHandling.h"
#include "PersonHandling.h"

int getPersoaneNr(std::string file_name)
{
	int persoane_nr = 0;

	std::ifstream file;
	std::string buffer;

	file.open(file_name);

	if (file.is_open())
	{
		int space_count = 0;
		while (std::getline(file, buffer))
		{
			persoane_nr++;
		}
		file.close();
	}
	else
	{
		std::string error_str = "Could not open/read/close the file " + file_name +
			".\nVerifica daca fisierul exista sau daca este folosit de un alt program.";
		throw std::invalid_argument(error_str);
	}

	return persoane_nr;
}

int* getStudentiId(void)
{
	int id, studenti_nr, i=0;
	studenti_nr = getPersoaneNr(STUDENTI_FILE);
	std::string id_string;
	int* id_arr = new int[studenti_nr];

	std::ifstream file;
	std::string buffer;
	

	file.open(STUDENTI_FILE);
	if (file.is_open())
	{
		while (std::getline(file, buffer))
		{
			std::istringstream ss(buffer);
			ss >> id_string;
			id_string = id_string.substr(1);
			if (isNum(id_string))
			{
				id = atoi(id_string.c_str());
				id_arr[i] = id;
				i++;
			}
			else
			{
				throw "The ID read from file is not correct.";
			}
		}
		file.close();
	}
	else
	{
		throw "Could not open/read/close the file " + std::string(STUDENTI_FILE) + ".";
	}

	return id_arr;
}

void to_lower(std::string& string)
{
	for (int i = 0; i < string.length(); i++)
	{
		string[i] = tolower(string[i]);
	}
}

std::string* getProfesoriNames(int index)
{
	int profesori_nr, i = 0;
	profesori_nr = getPersoaneNr(PROFESORI_FILE);
	std::string name;
	std::string* names = new std::string[profesori_nr];

	std::ifstream file;
	std::string buffer;


	file.open(PROFESORI_FILE);
	if (file.is_open())
	{
		while (std::getline(file, buffer))
		{
			std::istringstream ss(buffer);
			ss >> name;
			name = name.substr(1);
			to_lower(name);
			if(i > index)
				names[i] = name;
			i++;
		}
		file.close();
	}
	else
	{
		throw "Could not open/read/close the file " + std::string(STUDENTI_FILE) + ".";
	}

	return names;
}