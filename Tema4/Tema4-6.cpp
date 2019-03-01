/* Scrieti un program care citeste doua cuvinte si apoi decide daca sunt anagramde
 * (contin aceleasi litere in ordine diferita)
 */
 
#include <iostream>
#include <string>
 
std::string getAlphabet(void)
{
	std::string alphabet;
	char ch = 'a';
	for(int i = 0; i < 26; i++)
	{
		alphabet.push_back(ch);
		ch++;
	}
	
	return alphabet;
}	

bool isAnagram(std::string word1, std::string word2)
{
	std::string alphabet = getAlphabet();
	int letters_count[26] = {0}, index = 0;
	
	for(int i = 0; i < 26; i++)
	{
		k = 0;
		for(j = 1; j < word1.length(); j++)
		{
			if(word1[j] == alphabet[i])
			{
				letters_count[k]++;
			}
		}
	}
	
	for(int i = 0; i < 26; i++)
	{
		std::cout << alphabet[i] << " - " << letters_count[i];
	}

	
	return true;
}

int main(void)
{
	std::string word1, word2;
	
	std::cout << "Enter first word: ";
	std::getline(std::cin, word1);
	
	std::cout << "Enter second word: ";
	std::getline(std::cin, word2);
	
	if(isAnagram(word1, word2))
	{
		std::cout << "The words " << word1 << " and " << word2 << " are anagram.";
	}
	else
	{
		std::cout << "The words " << word1 << " and " << word2 << " are not anagram.";
	}
	
	return 0;
}