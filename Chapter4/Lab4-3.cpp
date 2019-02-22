/* Comparing floating points number */

#include <iostream>
#include <math.h>

bool is_close(double a, double b, double tolerance)
{
	if(fabs(a-b) <= tolerance)
		return true;
	
	return false;
}

int main(void)
{
	if(0.3 == 3 * 0.1)
	{
		std::cout << "The numbers are equals" << std::endl;
	}
	else
	{
		std::cout << "The numbers are not equals" << std::endl;
	}
	
	if(is_close(3 * 0.1, 0.3, 0.00000001))
	{
		std::cout << "The numbers are close enough" << std::endl;
	}
	else
	{
		std::cout << "The numbers are not close enough" << std::endl;
	}
	
	if(is_close(0.3, 3 * 0.1, 0.00000001))
	{
		std::cout << "The numbers are still close enough" << std::endl;
	}
	else
	{
		std::cout << "The numbers are not close enough" << std::endl;
	}
	
	if(is_close(3 * 0.1, 0.31, 0.00000001))
	{
		std::cout << "The numbers are still close enough" << std::endl;
	}
	else
	{
		std::cout << "The numbers are not close enough" << std::endl;
	}
	return 0;
}