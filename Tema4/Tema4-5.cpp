/* O functionalitate oferita de motoarele de cautare este inlaturarea cuvintelor foarte 
 * comune din textul cautat. Scrieti o functie care citeste cate doua randuri.
 * Primul precizeaza cuvintele de inlaturat, separate prin ','. Al doilea rand fraza din 
 * care aceste cuvinte trebuiesc inlaturate.
 */
 
#include <iostream>
#include <string>

std::string removeWords(std::string words[], std::string sentence, int words_number)
{
	for(int i = 0;se
}

int main(void)
{
	int comma_k = 0, k = 0;
	std::string *common_words, words_list, sentence, token = "";
	
	std::cout << "Enter the words to be ignored separated by \',\': " << std::endl;
	std::getline(std::cin, words_list);
	
	std::cout << "\nEnter the search sentence: " << std::endl;
	std::getline(std::cin, sentence);
	
	for(int i = 0; i < words_list.length(); i++)
	{
		if(words_list[i] == ',')
		{
			comma_k++;
		}
	}
	
	std::cout << "COMMA_K = " << comma_k << std::endl;
	common_words = new std::string[comma_k+1];
	
	for(int i = 0; i < words_list.length(); i++)
	{
		token += words_list[i]; // append letters
		if(words_list[i] == ',')
		{
			common_words[k] = token.substr(0, token.length()-1);
			k++;
			token = "";
		}
		
		if(k == comma_k)
		{
			common_words[comma_k] = token;
		}
	}
	
	removeWords(common_words, sentence, comma_k+1);
	
	for(int i = 0; i < comma_k+1; i++)
	{
		std::cout << i+1 << ". = " << common_words[i] << std::endl;
	}
	
	return 0;
}