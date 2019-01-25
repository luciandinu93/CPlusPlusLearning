/* Finding the value of pi
 *
 * One of the methods used to find the value of pi (not very effective) is the Leibniz formula.
 */

#include <iostream>

using namespace std;

int main(void)
{
    double pi4 = 0.;
    long n, k;

    cout << "Number of iterations: ";
    cin >> n;
    
    k = 0;
    for (double i = 1; i <= n*2; i=i+2.)
    {
        if ( k % 2 == 0)
        {
            pi4 = pi4 + 1./i;
            k++;
            cout << i << endl;
        }
        else
        {
            pi4 = pi4 - 1./i;
            k++;
            cout << i << endl;
        }
    }

    cout.precision(20);
    cout << "Pi = " << (pi4 * 4.) << endl;

    return 0;
}
