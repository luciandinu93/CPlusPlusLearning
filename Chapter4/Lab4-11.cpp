/* Text manipulation : anagrams */

#include <iostream>
#include <string>

int main(void)
{
	int pos, k1 = 0, k2 = 0;
	std::string text, text1, text2;
	std::getline(std::cin, text);
	
	pos = text.find(' ');
	
	text1 = text.substr(0, pos);
	text2 = text.substr(pos + 1);
	
	for(char c = 'a'; c <= 'z'; c++)
	{
		for(int i = 0; i < text1.length(); i++)
		{
			if(c == text1[i])
				k1++;
		}
		for(int i = 0; i < text2.length(); i++)
		{
			if(c == text2[i])
				k2++;
		}
		if(k1 != k2)
		{
			std::cout << "not anagrams" << std::endl;
			return 0;
		}
		k1 = 0;
		k2 = 0;
	}
	
	std::cout << "anagrams" << std::endl;
	
	return 0;
}