/* Fibonacci squence
 * 
 * The first Fibonacci is equal to 1;
 * The scond Fibonacci number is equal to 1 too;
 * The thirdm fourth and every subsequent Gibonacci number is equal to the sum of the previous two numbers;
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned short int n, i;
    unsigned long long int fib, prev0, prev1;

    cout << "Enter n: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prev0 = 1;
            fib = 1;
        }
        else if (i == 1)
        {
            prev1 = 1;
            fib = 1;
        }
        else 
        {
            fib = prev0 + prev1;
            prev0 = prev1;
            prev1 = fib;
        }
    }

    cout << "The " << n << "-th term of fibonacci is : " << fib << endl;

    return 0;
}
