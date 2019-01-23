/* Write a program that displays a sqare with the size x made of symbol @
 * x is read from keyboard
 * Also create an equilateral triange with the same size
 */

#include <iostream>

using namespace std;

int main(void)
{
    int x_initial, x;
    char c;

    c = '@';
    cout << "The size of sqare is ";
    cin >> x_initial;
    char v[x_initial][x_initial];          

    x = x_initial;

    // constructing the figures
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (i == 0 || j == 0 || i == x-1 || j == x-1)
                v[i][j] = c;
            else
                v[i][j] = ' ';
        }
    }

    // displaying the figures
    for (int i = 0; i < x; i++)
    {
	    for (int j = 0; j < x; j++)
	    {
            cout << v[i][j];
	    }   
        cout << endl;
    }
    return 0;
}
