/* Modelling fractions: part 1 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	std::string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};

Fraction::Fraction(int numerator, int denominator)
{
	if(denominator == 0)
		throw std::invalid_argument("Denominator can not be 0!");
	this->numerator = numerator;
	this->denominator = denominator;
}

std::string Fraction::toString()
{
	std::string fraction = "";
	if(numerator / denominator < 0)
	{
		fraction = fraction + "-";
	}
	if(numerator / denominator != 0)
	{
		fraction = fraction + std::to_string(std::abs(numerator/denominator)) + " ";
	}
	if(numerator % denominator != 0)
	{
		fraction = fraction + std::to_string(numerator % denominator) + "/" + std::to_string(std::abs(denominator));
	}
	
	return fraction;
}

double Fraction::toDouble()
{
	return (double)this->numerator / this->denominator;
}

// implement Fraction methods

int main(void)
{
	int num, den;
	std::string input = "";
	std::cout << "Enter a fraction in format \'[NUMERATOR] / [DENOMINATOR]\': ";
	std::getline(std::cin, input);
	
	// parse input and get numerator and denominator
	try
	{
		if(input[input.find('/')-1] != ' ')
		{
			std::cout << "Please use this format \'[NUMERATOR] / [DENOMINATOR]\', it seems you forget spaces." << std::endl;
			throw std::invalid_argument("Invalid format!");
		}
		else
		{
			num = atoi(input.substr(0, input.find('/') - 1).c_str());
			den = atoi(input.substr(input.find('/') + 1).c_str());
		}
		
		try
		{
			Fraction fraction(num, den);
			std::cout << "\n" << fraction.toString() << " is " << fraction.toDouble() << " in decimal." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Can not construct fraction beacuse " << e.what() << std::endl;
		}
	}
	catch(...)
	{
		std::cout << "Entered numbers are not valid:" << std::endl;
		std::cout << "Numerator: " << input.substr(0, input.find('/') - 1) << std::endl;
		std::cout << "Denominator: " << input.substr(input.find('/') + 1) << std::endl;
	}
	
	return 0;
}