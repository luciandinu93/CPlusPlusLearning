#include <iostream>

int main(void)
{
	float f = 123.456;
	float g = 1e100;
	int i = f;
	int j = g;
	
	std::cout << i << std::endl;
	std::cout << j << std::endl;
	
	return 0;
}