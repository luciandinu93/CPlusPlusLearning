/* Scrieti o functie care verifica daca un text introdus de la tastatura contine
 * o adresa de ip valabila, de forma x.x.x.x , x ia valori intre 0 si 255;
 */
 
#include <iostream>
#include <string>

int main(void)
{
	std::string ip_adr, numbers[4];
	int point_pos = 0, point_pos_arr[3];
	
	std::cout << "Introduceti adresa ip: ";
	std::getline(std::cin, ip_adr);
	
	for(int i = 0; i < 3; i++)
	{
		point_pos = ip_adr.find('.', point_pos);
		if(point_pos > 3)
		{
			std::cout << "One number is too big!" << std::endl;
			return 0;
		}
		else if(point_pos == std::string::npos)
		{
			std::cout << "Not enough number introduced!" << std::endl;
			return 0;
		}
		else
		{
			point_pos_arr[i] = point_pos;
			numbers[i] = ip_adr.substr(0, point_pos);
			for(int k = 0; k < numbers[i].length(); k++)
			{
				if(numbers[i][k] < '0' || numbers[i][k] > '9')
				{
					std::cout << "You can include only digits in your ip addres!" << std::endl;
					return 0;
				}
			}
			if(std::stoi(numbers[i]) > 255 || std::stoi(numbers[i]) < 0)
			{
				std::cout << "Numbers range is incorect, " << numbers[i] << "not in [0, 255]!" << std::endl;
				return 0;
			}
			ip_adr.erase(0, point_pos +1);
		}
		
		// the last number
		if(i == 2)
		{
			numbers[3] = ip_adr;
			if(numbers[3].length() > 3)
			{
				std::cout << "One number is too big!" << std::endl;
				return 0;
			}
			else if(numbers[3].length() == 0)
			{
				std::cout << "Not enough number introduced!" << std::endl;
				return 0;
			}
			
			for(int k = 0; k < numbers[3].length(); k++)
			{
				if(numbers[3][k] < '0' || numbers[3][k] > '9')
				{
					std::cout << "You can include only digits in your ip addres!" << std::endl;
					return 0;
				}
			}
			if(std::stoi(numbers[3]) > 255 || std::stoi(numbers[3]) < 0)
			{
				std::cout << "Numbers range is incorect, " << numbers[3] << "not in [0, 255]!" << std::endl;
				return 0;
			}
			
			ip_adr.erase(0);
		}
	}
	
	std::cout << "The IP address is correct!" << std::endl;
	
	return 0;
}