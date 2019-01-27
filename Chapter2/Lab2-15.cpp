/* Counting bits 
 *
 * Write a program that counts the ones (bits set to "1") in an integer variable.
 * Use unsigned long.
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned long int n, n_initial;
    unsigned short int i, counter;

    counter = 0;
    
    cout << "Enter a number: ";
    cin >> n;
    
    n_initial = n;

    for (i = 0; i < sizeof(n) * 8; i++)
    {
        if ( n & 1)
        {
            counter++;
        }

        n = n >> 1;
            
    }

    cout << "In " << n_initial << " are " << counter << " bits set." << endl;

    return 0;
}
