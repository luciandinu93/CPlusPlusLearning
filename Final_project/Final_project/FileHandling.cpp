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
		throw "Could not open/read/close the file " + file_name + ".";
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