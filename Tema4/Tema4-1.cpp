/* Scrieti un program care citeste un text introdus de utilizator si 
 * verifica daca acesta contine toate literele din alfabet - este o 
 * pangrama.
 * "The quick brown fox jumps over the lazy dog".
 */
 
#include <iostream>
#include <string>

void to_lower(std::string &text)
{
	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] >= 'A' && text[i] <= 'Z')
		{
			text[i] = text[i] - ('Z' - 'z');
		}
	}
}

int main(void)
{
	char alphabet[26], c = 'a';
	int aparitions[26] = {0}, letter;
	std::string sentence;
	
	std::cout << "Enter sentence to test if it is pangram: \n";
	std::getline(std::cin, sentence);
	
	to_lower(sentence);
	
	// create alphabet
	for(int i = 0; i <= 25; i++)
	{
		alphabet[i] = c + i;
	}
	
	for(int i = 0; i < sentence.length(); i++)
	{
		letter = sentence[i] - c;
		aparitions[letter]++;
	}
	
	for(int i = 0; i <= 25; i++)
	{
		if(aparitions[i] == 0)
		{
			std::cout << alphabet[i] << "-" << "0!!!" << std::endl;
			std::cout << "NO-not pangram" << std::endl;
			return 0;
		}
		std::cout << alphabet[i] << "-" << aparitions[i] << std::endl;
	}
	
	std::cout << "YES-pangram" << std::endl;
	
	return 0;
}