/* Text manipulation: Stop word elimination */

#include <iostream>
#include <string>

int main(void)
{
	char delimiter = ',';
	std::string stop_words, *words_list, sentence, token;
	int pos = 0, delim_counter = 0, k = 0;
	
	std::getline(std::cin, stop_words);
	std::getline(std::cin, sentence);
	
	for(int i = 0; i < stop_words.length(); i++)
	{
		if(stop_words[i] == delimiter)
			delim_counter++;
	}
	
	words_list = new std::string[delim_counter+1]; // allocate memory for all stop words
	
	while((pos = stop_words.find(delimiter)) != std::string::npos)
	{
		token = stop_words.substr(0, pos);
		words_list[k] = token;
		k++;
		stop_words.erase(0, pos + 1);
	}
	
	words_list[k] = stop_words.substr(0, pos); // last word
	
	token = "";
	k = 0;
	for(int ind = 0; ind < delim_counter+1; ind++)
	{
		int  start = 0, end = 0;
		
		for(int i = 0; i < sentence.length(); i++)
		{
			if(sentence[i].compare(" ") != 0)
			{
				token[k] = sentence[i];
				k++;
				std::cout << "found one" << std::endl;
			}
			else
			{
				std::cout << "sentence = " << token << std::endl;
				k = 0;
			}
		}
	}
	
	
	delete []words_list;
	
	return 0;
}