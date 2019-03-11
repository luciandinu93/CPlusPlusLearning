/* Creati o clasa care modeleaza numere complexe de forma z = a + b*i */

#include <iostream>
#include <cmath>

class Complex
{
public:
	Complex(double real, double imag);
	Complex add(Complex that);
	double abs();
	std::string to_string();
private:
	double real;
	double imag;
};

Complex::Complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

Complex Complex::add(Complex that)
{
	Complex sum(0, 0);
	sum.real = this->real + that.real;
	sum.imag = this->imag + that.imag;
	
	return sum;
}

double Complex::abs()
{
	int real = this->real;
	int imag = this->imag;
	
	return std::sqrt(real * real + imag * imag);
}

std::string Complex::to_string()
{
	std::string complex;
	complex = complex + "(" + std::to_string(this->real) + " + " + std::to_string(imag) + "i)";
	
	return complex;
}


int main()
{
	double real, imag;
	std::cout << "Enter the real part of C1: ";
	std::cin >> real;
	std::cout << "Enter the imag part of C1: ";
	std::cin >> imag;
	Complex c1(real, imag);
	std::cout << "First complex number is " << c1.to_string() << std::endl;
	
	std::cout << "Enter the real part of C2: ";
	std::cin >> real;
	std::cout << "Enter the imag part of C3: ";
	std::cin >> imag;
	Complex c2(real, imag);
	std::cout << "First complex number is " << c2.to_string() << std::endl;
	
	std::cout << c1.to_string() << " + " << c2.to_string() << " = " << c1.add(c2).to_string() << std::endl;
	std::cout << "ABS[" << c1.to_string() << "] = " << c1.abs() << std::endl;
	std::cout << "ABS[" << c2.to_string() << "] = " << c1.abs() << std::endl;
	
	return 0;
}