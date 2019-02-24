/* Text manipulation, duplicate white spaces 
 * 
 * TO DO: Write a program that will read a line of text and remove all duplicate white spaces. 
 */

#include <iostream>

int main(void)
{
	int k = 0;
	std::string sentence;
	std::getline(std::cin, sentence);
	
	for(int i = sentence.length() - 1; i >= 0; i--)
	{
		if(sentence[i] == ' ' && k == 0)
			k++;
		else if(sentence[i] == ' ' && k == 1)
		{
			sentence.erase(i, 1);
		}
		else
			k = 0;
	}
	
	std::cout << sentence;
	
	return 0;
}