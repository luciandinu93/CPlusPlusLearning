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
	int k;
	std::string alphabet = getAlphabet();
	int letters_count[26] = {0}, index = 0;
	
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < word1.length(); j++)
		{
			if(word1[j] == alphabet[i])
			{
				letters_count[i]++;
			}
		}
	}
	
	for(int i = 0; i < 26; i++)
	{
		k = 0;
		for(int j = 0; j < word2.length(); j++)
		{
			if(word2[j] == alphabet[i])
			{
				k++;
			}
		}
		if(k != letters_count[i])
			return false;
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
	
	if(word1.length() != word2.length())
	{
		std::cout << "The words " << word1 << " and " << word2 << " are not anagram.";	
	}
	else if(isAnagram(word1, word2))
	{
		std::cout << "The words " << word1 << " and " << word2 << " are anagram.";
	}
	else
	{
		std::cout << "The words " << word1 << " and " << word2 << " are not anagram.";
	}
	
	return 0;
}