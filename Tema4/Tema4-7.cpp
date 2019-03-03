/* Scrieti un program care citeste un text si verifica daca textul poate fi o parola valida:
 * - are 8 caractere
 * - contine cel putin o majuscula si o litera mica 
 * - contine cel putin o cifra
 * - contine cel putin un caracter special
 */
 
#include <iostream>
#include <string>

bool is8charLong(std::string password)
{
	if(password.length() == 8)
		return true;
	else
		return false;
}	

bool isUpperAndLower(std::string password)
{
	bool upper = false, lower = false;
	for(int i = 0; i < password.length(); i++)
	{
		if(password[i] >= 'a' && password[i] <= 'z')
			lower = true;
		if(password[i] >= 'A' && password[i] <= 'Z')
			upper = true;
	}
	
	return (upper && lower);
}

bool isDigit(std::string password)
{
	for(int i = 0; i < password.length(); i++)
	{
		if(password[i] >= '0' && password[i] <= '9')
			return true;
	}
	
	return false;
}

bool isSpecialChar(std::string password)
{
	for(int i = 0; i < password.length(); i++)
	{
		if( int(password[i]) >= 32 && int(password[i])<= 47 || int(password[i]) >= 58 && int(password[i])<= 64 ||
			int(password[i]) >= 91 && int(password[i])<= 96 || int(password[i]) >= 123 && int(password[i])<= 126)
			return true;
	}
	
	return false;
}


int main(void)
{
	std::string password;
	
	std::cout << "Alegeti o parola: ";
	std::getline(std::cin, password);
	
	if(!is8charLong(password))
	{
		std::cout << "Parola introdusa nu are lungimea de 8 caractere." << std::endl;
	}
	else if(!isUpperAndLower(password))
	{
		std::cout << "Parola nu contine cel putin o majuscula si o litera mica" << std::endl;
	}
	else if(!isDigit(password))
	{
		std::cout << "Parola nu contine cel putin o cifra" << std::endl;
	}
	else if(!isSpecialChar(password))
	{
		std::cout << "Parola nu contine cel putin un caracter special" << std::endl;
	}
	else
	{
		std::cout << "Parola salvata cu succes!" << std::endl;
	}
	
	return 0;
}