/* Postcad from Gizah
 */

#include <iostream>

using namespace std;

int main(void)
{
    unsigned short int n;

    cout << "Please enter the height of the piramids:";
    cin >> n;

    for (short int i = 0; i < n; i++)
    {
        for (short int j = 1; j <= n-i; j++)
        {
            cout << ' ';
        }
        for (short int k = 1; k <= (2 * i) - 1; k++)
        {
            if ( i < n)
            if (k == 1 || k == (2*i) - 1)
                cout << k;
            else
                cout << k;
            else if ( i == n)
                cout << k;
        }
        cout << endl;
    }

    return 0;
}
