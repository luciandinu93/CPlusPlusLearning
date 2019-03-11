/* Creati o clasa care retine informatii despre carti */

#include <iostream>
#include <string>
#include <stdexcept>

#define MAX 100

class Carte
{
public:
	Carte();
	std::string getAutor() {return this->autor;}
	int getNumarPagini() {return this->numar_pagini;}
	float getPret() {return this->pret;}
	void setAutor(std::string);
	void setNumarPagini(int);
	void setPret(float);
private:
	std::string autor;
	int numar_pagini;
	float pret;
};

Carte::Carte()
{
	this->autor = "";
	this->numar_pagini = 0;
	this->pret = 0.0;
}

void Carte::setAutor(std::string autor)
{
	if(autor.empty())
		throw std::invalid_argument("Va rog introduceti un autor");
	this->autor = autor;
}

void Carte::setNumarPagini(int numar_pagini)
{
	if(numar_pagini <= 0)
		throw std::invalid_argument("Numarul de pagini nu este corect");
	this->numar_pagini = numar_pagini;
}

void Carte::setPret(float pret)
{
	if(pret <= 0)
		throw std::invalid_argument("Pretul introdus nu este corect");
	this->pret = pret;
}

int main()
{
	std::string autor;
	int numar_pagini;
	float pret;
	int comanda = 1, i = 0;
	
	Carte *carti[MAX];
	
	while(comanda)
	{
		std::cout << "Tastati 1 pentru a introduce o carte sau 0 pentru a le afisa: ";
		std::cin >> comanda;
	
		if(comanda == 1)
		{
			std::cout << "Ati ales sa introduceti o carte!" << std::endl;
			std::cout << "Nume autor: ";
			std::cin.ignore();
			std::getline(std::cin, autor);
			std::cout << "Numar de pagini carte: ";
			std::cin >> numar_pagini;
			std::cout << "Pret carte: ";
			std::cin >> pret;
	
			try
			{
				// creeaza o carte 
				carti[i] = new Carte();

				carti[i]->setAutor(autor);
				carti[i]->setNumarPagini(numar_pagini);
				carti[i]->setPret(pret);
				i++;
			}
			catch(const std::exception& e)
			{
				std::cout << "Nu am putut adauga cartea deoarece " << e.what() << std::endl;
			}
		}
		else if(comanda != 0)
		{
			std::cout << "Comanda nu exista!" << std::endl;
			return 1;
		}
	}
	
	if(i == 0)
		std::cout << "Nu exista carti!" << std::endl;
	else
	{
		for(int j = 0; j < i; j++)
		{
			std::cout << j+1 << ". " << carti[j]->getAutor() << " are " << carti[j]->getNumarPagini() <<
			"de pagini si costa " << carti[j]->getPret() << " RON" << std::endl;
		}
	}
	
	return 0;
}

