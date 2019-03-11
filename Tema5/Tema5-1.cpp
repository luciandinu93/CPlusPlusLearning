/* Creati o clasa numita Persoana care sa contina un camp nume si unu varsta */

#include <iostream>
#include <string>
#include <stdexcept>

class Persoana
{
public:
	Persoana();
	Persoana(std::string nume, int varsta);
	void display();
	void setNume(std::string nume);
	std::string getNume();
	void setVarsta(int varsta);
	int getVarsta();
private:
	std::string nume;
	int varsta;
};


Persoana::Persoana()
{
	this->nume = "";
	this->varsta = 0;
}

Persoana::Persoana(std::string nume, int varsta)
{
	if(nume.empty())
		throw std::invalid_argument("No name given");
	if(varsta < 0)
		throw std::invalid_argument("Invalid age given");
	this->nume = nume;
	this->varsta = varsta;
}

void Persoana::display()
{
	std::cout << this->nume << ", " << this->varsta << " years old";
}

void Persoana::setNume(std::string nume)
{
	this->nume = nume;
}

std::string Persoana::getNume()
{
	return this->nume;
}

void Persoana::setVarsta(int varsta)
{
	this->varsta = varsta;
}


int Persoana::getVarsta()
{
	return this->varsta;
}

int main(void)
{
	std::string nume;
	int varsta;
	
	try
	{
		Persoana pers1;
		Persoana pers2("Ion", 40);
		
		std::cout << "Enter the name of Ion's friend: ";
		std::getline(std::cin, nume);
		
		std::cout << "Enter the age of Ion's friend: ";
		std::cin >> varsta;
		
		pers1.setNume(nume);
		pers1.setVarsta(varsta);
		
		pers1.display();
		std::cout <<" is friend with ";
		pers2.display();
		std::cout << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Can not display because " << e.what() << std::endl;
	}
	
	
	return 0;
}









