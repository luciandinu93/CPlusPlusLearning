/* Creati o clasa numita Comanda */

#include <iostream>
#include <string>
#include <stdexcept>

class Comanda
{
public:
	Comanda();
	void setNumeArticol(std::string nume_articol);
	void setPret(float pret);
	void setCantitate(int cantitate);
	std::string getNumeArticol();
	float getPret();
	int getCantitate();
private:
	std::string nume_articol;
	float pret;
	int cantitate;
};


Comanda::Comanda()
{
	this->nume_articol = "";
	this->pret = 0.0;
	this->cantitate = 0;
}

void Comanda::setNumeArticol(std::string nume_articol)
{
	if(nume_articol.empty())
		throw std::invalid_argument("Name is not specified");
	this->nume_articol = nume_articol;
}

void Comanda::setPret(float pret)
{
	if(pret <= 0)
		throw std::invalid_argument("The product is free ? Invalid value for price");
	this->pret = pret;
}

void Comanda::setCantitate(int cantitate)
{
	if(cantitate < 0)
		throw std::invalid_argument("The quantity can't be negative");
	this->cantitate = cantitate;
}

std::string Comanda::getNumeArticol()
{
	return this->nume_articol;
}

float Comanda::getPret()
{
	return this->pret;
}

int Comanda::getCantitate()
{
	return this->cantitate;
}

int main()
{
	std::string nume_articol;
	float pret;
	int cantitate;
	Comanda com;
	
	std::cout << "Introduceti numele produsului: ";
	std::getline(std::cin, nume_articol);
	
	std::cout << "Introduceti pretul produsului: ";
	std::cin >> pret;
	
	std::cout << "Introduceti cantiatea: ";
	std::cin >> cantitate;
	
	// process command
	try
	{
		com.setNumeArticol(nume_articol);
		com.setPret(pret);
		com.setCantitate(cantitate);
	}
	catch(const std::exception& e)
	{
		std::cout << "Command is invalid becasue " << e.what();
	}
	
	std::cout << "Ati cumparat " << com.getCantitate() << " X " << com.getNumeArticol() << " in valoare de " << 
	com.getCantitate() * com.getPret() << "$." << std::endl;
	
	return 0;
}







