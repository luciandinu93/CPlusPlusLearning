/* Finding positive powers of 2
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned short int n, i;
    unsigned long long int number;

    cout << "Show the n-th power two! n = ";
    cin >> n;
   
    cout << "Size of : " << sizeof(number) << endl;
    number = 1;

    for (i = 1; i <= n; i++)
    {
        number *= 2; 
        cout << "number = " << number << endl;
        cout << "i = " << i << endl;
    }

    cout << "The " << n << "-th power of 2 is = " << number << endl;

    return 0;
}
