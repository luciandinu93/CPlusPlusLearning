/* String manipulation: pangrams
 */

#include <iostream>
#include <string>
#include <algorithm>

void tolower(std::string &text)
{
	int len = text.length();
	
	for(int i = 0; i < len; i++)
	{
		if(text[i] >= 'A' && text[i] <= 'Z')
		{
			text[i] = text[i] - ('Z' - 'z');
		}
	}
}

bool isPangram(std::string text)
{
	int len = text.length();
	for(char c = 'a'; c <= 'z'; c++)
	{
		int k = 0;
		for(int i = 0; i < len; i++)
		{
			if(c == text[i])
			{
				k++;
			}
		}
		if(k == 0)
		{
			return false;
		}
	}
	return true;
}

void displayLetters(std::string text)
{
	int len = text.length();
	for(char c = 'a'; c <= 'z'; c++)
	{
		int k = 0;
		for(int i = 0; i < len; i++)
		{
			if(c == text[i])
			{
				k++;
			}
		}
		std::cout << c << "-" << k << std::endl;
	}
}

int main(void)
{
	char c = 'a';
	std::string text;
	
	std::cout << "Enter text: ";
	getline(std::cin, text);
	
	tolower(text); // lower case
	
	if(isPangram(text))
	{
		std::cout << "Pangram" << std::endl;
	}
	else
	{
		std::cout << "Not pangram" << std::endl;
	}
	
	displayLetters(text);
	
	return 0;
}