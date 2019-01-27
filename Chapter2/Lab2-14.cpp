/* Lab2.3.9 The riddle
 * 
 * The size of the sqare side is always odd
 */

#include <iostream>

using namespace std;

int main(void)
{
    int n;

    cout << "Enter an odd number:";
    cin >> n;
    while(1)
    {
        if (n % 2 == 0)
        {
            cout << "Entered number is not a positive odd number. Try again: ";
            cin >> n;
        }
        else
            break;
    }
    cout << "Numarul cautat este : " << 2 + n * (n - 2) << endl;

       
    return 0;
}
