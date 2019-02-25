/* Scrieti o functie care inlocuieste spatiile albe duplicate cu un singur spatiu */

#include <iostream>
#include <string>

int main(void)
{
	std::string sentence;
	
	std::cout << "Enter the sentence with duplicated spaces : " << std::endl;
	std::getline(std::cin, sentence);
	
	for(int i = sentence.length() - 1; i >= 0; i--)
	{
		if(sentence[i] == ' ')
		{
			if(sentence[i-1] == ' ')
				sentence.erase(i, 1);
		}
		
	}
	
	// verify if start with space
	if(sentence[0] == ' ')
		sentence = sentence.substr(1);
	
	std::cout << "\nSentence without duplicated spaces : " << std::endl;
	std::cout << sentence << std::endl;
	
	return 0;
}