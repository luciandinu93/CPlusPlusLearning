/* Write a programm that displays the numbers from 1 to x,
 * where x is an int writen from keyboard. Write this program using a while,
 * a do while and a for instruction
 */

#include <iostream>

using namespace std;

int main()
{
    
    int i, x, x_initial;

    cout << "Introduceti nr. x: ";
    cin >> x_initial;
    
    i = 1;
    x = x_initial;
    cout << "\n*** Displaying number in while loop ***" << endl;
    while (x)
    {
        cout << i << endl;
        i++;
        x--;
    }
    
    i = 1;
    x = x_initial;
    cout << "\n*** Displaying number in do while loop ***" << endl;
    do
    {
        cout << i << endl;
        i++;
        x--;
    } while(x != 0);

    i = 1;
    x = x_initial;
    cout << "\n*** Displaying number in for loop ***" << endl;
    for (i; i <= x; i++)
        cout << i << endl;

    return 0;
}
