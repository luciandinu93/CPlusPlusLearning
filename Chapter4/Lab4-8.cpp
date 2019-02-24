/* Text manipulation: eliminate duplicates */

#include <iostream>
#include <string>

int main(void)
{
	std::string sentence, word, next_word;
	int space_index, old_index;

	std::getline(std::cin, sentence);

	word = "";
	next_word = "";
	space_index = sentence.find(" ");

	while(space_index != -1)
	{
		if(word.empty())
		{
			word = sentence.substr(0, space_index);
			old_index = space_index;
			space_index = sentence.find(" ", old_index + 1);
			next_word = sentence.substr(old_index + 1, space_index - old_index);
		}
		else
		{
			word = next_word;
			old_index = space_index;
			space_index = sentence.find(" ", old_index + 1);
			next_word = sentence.substr(old_index + 1, space_index - old_index);
		}

		if(word.compare(next_word) == 0)
		{
			sentence.erase(old_index, space_index - old_index);
		}
		std::cout << "word = " << word << std::endl;
		std::cout << "next_word = " << next_word << std::endl;
	}

	std::cout << sentence << "\n";

	return 0;
}
