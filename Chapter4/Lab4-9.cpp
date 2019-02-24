/* Text manipulation find and replace */

#include <iostream>
#include <string>

int main(void)
{
	int index, end_index;
	std::string from;
	std::getline(std::cin, from);

	std::string to;
	std::getline(std::cin, to);

	std::string sentence;
	std::getline(std::cin, sentence);

	index = sentence.find(from);
	if(index == -1)
	{
		std::cout << "Can not find your string" << std::endl;
		return 1;
	}
	end_index = sentence.find_last_of(from);

	while(index != -1)
	{
		if(from.compare(to) >= 0)
		{
			sentence.replace(index, to.length(), to);
			index = sentence.find(from);
			end_index = sentence.find_last_of(from);
		}
		else
		{
			sentence.replace(index, from.length(), to);
			index = sentence.find(from);
			end_index = sentence.find_last_of(from);
		}
		
	}

	std::cout << sentence << "\n";

	return 0;
}
