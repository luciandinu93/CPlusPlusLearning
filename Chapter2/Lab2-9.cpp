/* Finding negative powers of 2
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned short int n, i;
    double number;
    
    number = 1;

    cout << "Enter n: ";
    cin >> n;

    if (n == 0)
        cout << number;

    for (i = 1; i <= n; i++)
    {
        number = number * (1. / 2.); 
    }
    cout.precision(20);
    cout << fixed << number << endl;

    return 0;
}
