/* Drawing squares
 *
 * 1. ask the user to enter a positive integer value greater than 1 (n)
 * 2. check the entered value and if it isn"t legal, output a message stating the reason
 * 3. draw a sqare with a side of n
 */

#include <iostream>

using namespace std;

int main(void)
{
    int n ;

    cout << "Enter a positive integer value grater than 1 and smaller than 26:";
    cin >> n;
    
    while (n < 1 || n > 25)
    {
        cout << "Number " << n << " is not > 1 or < 25. Enter another value:";
        cin >> n;
    }

    cout << "+";
    for (int i = 0; i < n; i++)
        cout << "-";
    cout << "+" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < n; j++)
            cout << " ";
        cout << "|" << endl;
    }
    cout << "+";
    for (int i = 0; i < n; i++)
        cout << "-";
    cout << "+" << endl;

    return 0;
}
