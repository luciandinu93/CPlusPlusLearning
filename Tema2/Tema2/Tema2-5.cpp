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
    char v[2*x_initial][x_initial];          

    x = x_initial;

    // writing first line
    for (int i = 0; i < 2 * x; i++)
    {
        if (i % 2 == 0)
        {
            v[i][0] = c;
        }
        else
        {
            v[i][0] = ' ';
        }
    }

	// writing the body of the sqare
	for (int i = 0; i< 2 * x; i++)
	{
		for (int j = 1; j < x - 1; j++)
		{
			if (i == 0 || j == x-1 || i == 2*(x-1))
				v[i][j] = c;
			else
				v[i][j] = ' ';
		}
		
	}
	
	// writing last line of the sqare
	for (int i = 0; i < 2 * x; i++)
    {
        if (i % 2 == 0)
        {
            v[i][x-1] = c;
        }
        else
        {
            v[i][x-1] = ' ';
        }
    }
	
    // displaying the figures
    for (int i = 0; i < x; i++)
    {
		for (int j = 0; j < 2 * x; j++)
		{
			cout << v[j][i];
		}
		cout << endl;
    }
	
	cout << "/n--- Drawing an equilateral triangle --- /n";
    // NU STIU CUM FUNCTIONEAZA :(
    for (int i = 0; i < x; i++)
    {
        for (int y = 0; y < x; y++)
            cout << " ";
        for (int j = x - i; j > 0; j--)
            cout << " ";
        for (int k = 0; k < 2 * i + 1; k++)
            cout << "@";
        cout << endl;
    }
	
    return 0;
}
