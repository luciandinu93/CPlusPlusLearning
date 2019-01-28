/* Write a program that calculates the sum of numbers from 1 to 10
 * Write the program using following instructions:
 * while, do{}while and for
 */

#include <iostream>

using namespace std;

int main(void)
{
    int sum, i;
    
    sum = 0;
    i = 0;
    cout << "\n*** Displaying the sum of numbers from 1 to 10 (WHILE) ***" << endl;
    while (i < 10)
    {
        ++i;
        sum += i;
    }
    cout << "Sum = " << sum;

    sum = 0;
    i = 0;
    cout << "\n*** Displaying the sum of numbers from 1 to 10 (DO-WHILE) ***" << endl;
    do
    {
        ++i;
        sum += i;
    }while (i < 10);
    cout << "Sum = " << sum;

    sum = 0;
    i = 0;
    cout << "\n*** Displaying the sum of numbers from 1 to 10 (FOR) ***" << endl;
    for (i = 1; i <= 10; i++)
    {
        sum += i;
    }
    cout << "Sum = " << sum;

    return 0;
}
