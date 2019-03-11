/* Modelling fractions: part 3 */

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
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
	bool isGreaterThan(Fraction that);
	bool isLessThan(Fraction that);
	bool isEqual(Fraction that);
private:
	int numerator;
	int denominator;
	void reduce();
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
	int num = this->numerator;
	int den = this->denominator;

	if(num * den < 0)
	{
		num = std::abs(num);
		den = std::abs(den);
		
		if(num % den == 0)
			fraction = fraction + "-" + std::to_string(num / den);
		else if(num / den == 0)
			fraction = fraction + "-" + std::to_string(num) + "/" + std::to_string(den);
		else
			fraction = fraction + "-" + std::to_string(num / den) + " " + std::to_string(num % den) +
				"/" + std::to_string(den);
	}
	else
	{
		if(num % den == 0)
			fraction = fraction + std::to_string(num / den);
		else if(num / den == 0)
			fraction = fraction + std::to_string(num) + "/" + std::to_string(den);
		else
			fraction = fraction + std::to_string(num / den) + " " + std::to_string(num % den) +
				"/" + std::to_string(den);
	}
	
	return fraction;
}

double Fraction::toDouble()
{
	return (double)this->numerator / this->denominator;
}

Fraction Fraction::plus(Fraction that)
{
	int den = this->denominator * that.denominator;
	int num = that.denominator * this->numerator + this->denominator * that.numerator;
	
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::minus(Fraction that)
{
	int den = this->denominator * that.denominator;
	int num = that.denominator * this->numerator - this->denominator * that.numerator;
	
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	
	result.reduce();
	return result;
}

Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	
	result.reduce();
	return result;
}

bool Fraction::isGreaterThan(Fraction that)
{
	int num1, num2, den1, den2, max = 0;
	num1 = this->numerator;
	num2 = that.numerator;
	den1 = this->denominator;
	den2 = that.denominator;
	if(den1 == den2)
	{
		if(num1 > num2)
			return true;
		else
			return false;
	}
	max = num1 * den2;
	if(max > num2 * den1)
		return true;
	else
		return false;
}
bool Fraction::isLessThan(Fraction that)
{
	int num1, num2, den1, den2, max = 0;
	num1 = this->numerator;
	num2 = that.numerator;
	den1 = this->denominator;
	den2 = that.denominator;
	if(den1 == den2)
	{
		if(num1 < num2)
			return true;
		else
			return false;
	}
	max = num1 * den2;
	if(max < num2 * den1)
		return true;
	else
		return false;
}
bool Fraction::isEqual(Fraction that)
{
	int num1, num2, den1, den2, max = 0;
	num1 = this->numerator;
	num2 = that.numerator;
	den1 = this->denominator;
	den2 = that.denominator;
	if(den1 == den2)
	{
		if(num1 == num2)
			return true;
		else
			return false;
	}
	max = num1 * den2;
	if(max == num2 * den1)
		return true;
	else
		return false;
}

int GCD(int num, int den)
{
    int temp; // temporary value for swaping two ints
	num = std::abs(num);
	den = std::abs(den);

	if(!num)
		return den;
	if(!den)
		return num;
	while(1)
	{
	    temp = den;
		den = num % den;
		num = temp;
		if(num % den == 0)
		{
			return den;
		}
	}

	return -1;
}

void Fraction::reduce()
{
	int gcd = GCD(this->numerator, this->denominator);
	
	this->numerator = this->numerator / gcd;
	this->denominator = this->denominator / gcd;
}

bool obtainNumAndDen(std::string input, int &num, int &den)
{
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
		return true;
	}
	catch(...)
	{
		std::cout << "Entered numbers are not valid:" << std::endl;
		std::cout << "Numerator: " << input.substr(0, input.find('/') - 1) << std::endl;
		std::cout << "Denominator: " << input.substr(input.find('/') + 1) << std::endl;
		return false;
	}
	return false;
}

int main(void)
{
	int num, den;
	std::string input = "", input2 = "";
	
	// parse input and get numerator and denominator
	std::cout << "Enter first fraction in format \'[NUMERATOR] / [DENOMINATOR]\': ";
	std::getline(std::cin, input);
	if(obtainNumAndDen(input, num, den))
	{
		try
		{
			Fraction fraction1(num, den);
			
			std::cout << "Enter second fraction in format \'[NUMERATOR] / [DENOMINATOR]\': ";
			std::getline(std::cin, input2);
			if(obtainNumAndDen(input2, num, den))
			{
				try
				{
					Fraction fraction2(num, den);
					
					if(fraction1.isEqual(fraction2))
						std::cout << fraction1.toString() << " = " << fraction2.toString() << std::endl;
					else if(fraction1.isGreaterThan(fraction2))
						std::cout << fraction1.toString() << " > " << fraction2.toString() << std::endl;
					else if(fraction2.isLessThan(fraction2))
						std::cout << fraction1.toString() << " < " << fraction2.toString() << std::endl;
					else
						throw std::invalid_argument("There is a problem with your fractions, can not compare them!");
				}
				catch(const std::exception& e)
				{
					std::cout << "Can not construct fraction beacuse " << e.what() << std::endl;
				}
			}
		}
		catch(const std::exception& e)
		{
			std::cout << "Can not construct fraction beacuse " << e.what() << std::endl;
		}
		
	}
	
	return 0;
}