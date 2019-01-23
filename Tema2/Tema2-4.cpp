/* Write a program that ask the user to introduce positive numbers.
 * When the user introduce -1, it will be displayed the biggest number introduced.
 */

#include <iostream>

using namespace std;

int main(void)
{
    int  number, max;

    max = 0;
    while (number != -1)
    {
        cout << "Enter a positive number or \'-1\' to stop: ";
        cin >> number;
        
        if (max < number)
            max = number;
    }

    cout << "\nThe biggest number introdued is " << max << "." << endl;

    return 0;
}
