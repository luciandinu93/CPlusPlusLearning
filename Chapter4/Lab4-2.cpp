/* Write a program that, given a number N, will calculate the sum of all numbers int the range [1..N]
 * where N up to 100,000
 */

#include <iostream>

int main(void)
{
	unsigned int n;
	unsigned long long int sum = 0;
	
	std::cout << "Enter value of n: ";
	std::cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		sum += i;
	}
	
	std::cout << sum << std::endl;
	
	return 0;
}