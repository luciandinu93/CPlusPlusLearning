/* Prime numbers */

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num)
{
    if(num == 0 || num == 1)
        return 0;

    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0)
        {
            return 0;
        }

    return 1;
}

int main(void)
{
    for(int i = 0; i <= 21; i++)
        if(isPrime(i))
            cout << i << " ";
    cout << endl;

    return 0;
}
