#include "FileHandling.h"

int* getStudentiId(void)
{
	int id, studenti_nr, i=0;
	studenti_nr = getStudentiNr();
	int* id_arr = new int[studenti_nr];

	std::ifstream file;
	std::string buffer;
	std::stringstream ss;

	file.open("STUDENTI.TXT");
	if (file.is_open())
	{
		while (std::getline(file, buffer))
		{
			ss << buffer;
			try
			{
				id = atoi(ss.str().c_str());
				id_arr[i] = id;
				i++;
			}
			catch (...)
			{
				std::cout << "The file is invalid, id not an int!" << std::endl;
			}
		}
		file.close();
	}
	else
	{
		throw "Could not open/read/close the file STUDENTI.TXT.";
	}

	return id_arr;
}

int getStudentiNr(void)
{
	int studenti_nr = 0;

	std::ifstream file;
	std::string buffer;
	std::stringstream ss;

	file.open("STUDENTI.TXT");

	if (file.is_open())
	{
		while (std::getline(file, buffer))
		{
			ss << buffer << " " << buffer << " " << buffer;
			studenti_nr++;
		}
		file.close();
	}
	else
	{
		throw "Could not open/read/close the file STUDENTI.TXT.";
	}

	return studenti_nr;
}