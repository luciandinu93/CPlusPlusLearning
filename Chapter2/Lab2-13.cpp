/* Factorial iterative
 */

#include <iostream>

using namespace std;

int main(void)
{
    int n, i;
    unsigned long long int result;

    cout << "Enter n:";
    cin >> n;
    
    result = 1;

    for (i = 1; i <= n; i++)
    {
        result *= i;
    }

    cout << n << "! = " << result << endl;

    return 0;
}
