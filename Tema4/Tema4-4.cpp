/* Scrieti o functie care primeste drept paramaetru un CNP si extrage data nasterii a persoanei in formatul zz-ll-aaaa */

#include <iostream>
#include <string>

std::string extractBirthDay(std::string CNP)
{
	std::string birthDay, month, day;
	int year;
	
	year = stoi(CNP.substr(1, 2));
	if(year >= 0 && year <= 40)
	{
		year = 2000 + year;
	}
	else
	{
		year = 1900 + year;
	}
	
	month = CNP.substr(3, 2);

	day = CNP.substr(5,2);
	
	// format the birthDay string
	birthDay.append(day);
	birthDay.append("-" + month);
	birthDay.append("-" + std::to_string(year));

	return birthDay;
}

int main(void)
{
	std::string CNP;
	bool is_correct = false;
	int digit_counter = 0;
	
	while(!is_correct)
	{
		std::cout << "Enter a valid CNP: ";
		std::getline(std::cin, CNP);
		
		if(CNP.length() != 13)
		{
			std::cout << "The CNP must have exactly 13 digits! Try again!" << std::endl;
			continue;
		}
		
		for(int i = 0; i < CNP.length(); i++)
		{
			if(CNP[i] < '0' || CNP[i] > '9')
			{
				std::cout << "The CNP must contain only digits! Try again!" << std::endl;
				digit_counter = 0;
				break;
			}
			else
			{
				digit_counter++;
			}
		}
		if(digit_counter == 13)
			is_correct = true;
	}
	
	std::cout << "Your birthsday in format (zz-ll-yyyy) is: " << extractBirthDay(CNP) << std::endl;
	
	return 0;
}