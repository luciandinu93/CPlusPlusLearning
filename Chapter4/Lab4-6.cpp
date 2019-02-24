/* String in functions: IP numbers
 * Return possibilities:
 * - Correct IP;
 * - Too many characters in a part
 * - Too many parts
 * - Only digits and dots allowed
 * - Too big value of a part
 * - Incorrect parts count
 */

#include <iostream>
#include <string>

const std::string verifyIP(std::string ip)
{
	int dot_number = 0;
	int ip_len = ip.length();
	int dots_pos[3];
	std::string numbers[4];

	for(int i = 0; i < ip_len; i++)
	{
		if(ip[i] == '.')
		{
			dots_pos[dot_number] = i;
			if(dot_number == 0)
				numbers[dot_number] = ip.substr(0, i);
			else if(dot_number == 2)
			{
				numbers[dot_number] = ip.substr(dots_pos[dot_number - 1] + 1, i - dots_pos[dot_number - 1] - 1);
				numbers[dot_number+1] = ip.substr(dots_pos[dot_number] + 1);
			}
			else
				numbers[dot_number] = ip.substr(dots_pos[dot_number - 1] + 1, i - dots_pos[dot_number - 1] - 1);
			dot_number++;
			
			if(dot_number > 3)
				return "Too many parts";
			
			for(int j = 0; j < dot_number; j++)
			{
				for(int k = 0; k < numbers[j].length(); k++)
				{
					if(numbers[j][k] < '0' || numbers[j][k] > '9')
						return "Only digits and dots allowed";
				}
				if(numbers[j].length() > 3)
					return "Too many characters in a part";
				else if(std::stoi(numbers[j]) > 255)
					return "Too big value of a part"; 
			}
			
			if(dot_number == 3)
				for(int k = 0; k < numbers[3].length(); k++)
				{
					if(numbers[3][k] < '0' || numbers[3][k] > '9')
						return "Only digits and dots allowed";
				}
			if(dot_number == 3 && numbers[3].length() > 3)
				return "Too many characters in a part";
			else if(dot_number == 3 && std::stoi(numbers[3]) > 255)
				return "Too big value of a part";
		}
	}
	if(dot_number != 3)
		return "Incorrect parts count";

	return "Correct IP";

}

int main(void)
{
	std::string IP;

	getline(std::cin, IP);

	std::cout << verifyIP(IP) << std::endl;

	return 0;
}
