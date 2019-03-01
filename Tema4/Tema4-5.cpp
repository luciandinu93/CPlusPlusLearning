/* O functionalitate oferita de motoarele de cautare este inlaturarea cuvintelor foarte
 * comune din textul cautat. Scrieti o functie care citeste cate doua randuri.
 * Primul precizeaza cuvintele de inlaturat, separate prin ','. Al doilea rand fraza din
 * care aceste cuvinte trebuiesc inlaturate.
 */

#include <iostream>
#include <string>

void removeWords(std::string words[], std::string &sentence, int words_number)
{
	int index, first, last;
	for(int i = 0; i < words_number; i++)
	{
		index = 0;
		while(index != std::string::npos)
		{
			index = sentence.find(words[i], index);
			first = index - 1;
			last = index + words[i].length();
			if(last > sentence.length()-1)
            {
                last = std::string::npos;
            }
            else
            {
                last = index + words[i].length();
            }

			if(index == 0)
			{
				if(sentence[last] == ' ')
				{
					sentence.erase(index, words[i].length()+1);
					index++;
					continue;
				}
			}
			else if(last == std::string::npos)
            {
                if(words[i].compare(sentence.substr(index)) == 0)
                    sentence.erase(index);
            }
            else if(sentence[first] == ' ' && sentence[last] == ' ')
			{
                sentence.erase(index, words[i].length()+1);
			}

			if(index != -1)
                index++;
		}
	}
}

void displaySentence(std::string sentence)
{
	std::cout << "\nThe new sentence is :" << std::endl;
	std::cout << sentence << std::endl;
}

int getCommaNumber(std::string words_list)
{
	int comma_k = 0;

	for(int i = 0; i < words_list.length(); i++)
	{
		if(words_list[i] == ',')
		{
			comma_k++;
		}
	}

	return comma_k;
}

void allocSpace(std::string *&common_words, int words_k)
{
	common_words = new std::string[words_k];
}

	int main(void)
	{
		int words_k = 0, comma_k = 0, k = 0;
		std::string *common_words, words_list, sentence, token = "";

		std::cout << "Enter the words to be ignored separated by \',\': " << std::endl;
		std::getline(std::cin, words_list);

		std::cout << "\nEnter the search sentence: " << std::endl;
		std::getline(std::cin, sentence);

		comma_k = getCommaNumber(words_list);
		words_k = comma_k + 1;

		std::cout << "words_k = " << words_k << std::endl;

		allocSpace(common_words, words_k);

		// get the common_words
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

		displaySentence(sentence);

		for(int i = 0; i < comma_k+1; i++)
		{
			std::cout << i+1 << ". = " << common_words[i] << std::endl;
		}

		return 0;
	}
