/* O functionalitate oferita de motoarele de cautare este inlaturarea cuvintelor foarte 
 * comune din textul cautat. Scrieti o functie care citeste cate doua randuri.
 * Primul precizeaza cuvintele de inlaturat, separate prin ','. Al doilea rand fraza din 
 * care aceste cuvinte trebuiesc inlaturate.
 */
 
#include <iostream>
#include <string>

void transferWords(std::string src, std::string &out, int &word_k)
{
	int comma_k = 0;
	std::string token;
	word_k = 0;
	for(int i = 0; i < src.length(); i++)
	{
		if(src[i] == ',')
			comma_k++;
	}
	
	// allocate memory in string
	out = new std::string[comma_k+1];
	
	for(int i = 0; i < src.length(); i++)
	{
		token = "";
		if(src[i] == ',')
		{
			out[word_k] = token;
			word_k++;
			token = "";
		}
			
		else
			token.append(std::to_string(src[i]));
	}
}

int main(void)
{
	int word_k;
	std::string *common_words, words_list, sentence;
	
	std::cout << "Enter the words to be ignored separated by \',\': " << std::endl;
	std::getline(std::cin, words_list);
	
	std::cout << "\nEnter the search sentence: " << std::endl;
	std::getline(std::cin, sentence);
	
	transferWords(words_list, common_words, word_k);
	
	for(int i = 0; i < word_k; i++)
	{
		std::cout << "word[" << i+1 << "] = " << common_words[i] << std::endl;
	}
	
	return 0;
}