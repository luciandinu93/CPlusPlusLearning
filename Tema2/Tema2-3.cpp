/* Write a program that calculates the sum of digits of a number read from keyboard.
 * Calculate the sum of odd digits from the number
 */

#include <iostream>

using namespace std;

int main(void)
{
    int x_initial, x;
    short int sum;
    unsigned char digit;

    cout << "Enter a number: ";
    cin >> x_initial;

    sum = 0;    
    x = x_initial;
    while (x)
    {
        digit = x % 10;  
        x /= 10;
        sum += digit;
    }
    cout << "Sum of digits = " << sum << endl;

    sum = 0;
    x = x_initial;
    while (x)
    {
        digit = x % 10;
        x /= 10;
     	if (digit % 2 != 0)
	    sum += digit;
    }
    cout << "\nSum of odd digits = " << sum << endl;

    return 0;
}
