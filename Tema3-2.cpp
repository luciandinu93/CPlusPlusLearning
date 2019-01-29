/* Scrieti un program care roaga utilizatorul sa introduca doua numere si apoi sa apese:
 *
 * 1. Tasta s pentru a calcula suma numerelor;
 * 2. Tasta p pentru produsul numerelor;
 * 3. Tasta r pentru radicalul primului numarul;
 * 4. Tasta n pentru reintroducerea numerelor;
 * 5. Tasta x pentru incetarea rularii programului;
 */

#include <iostream>
#include <cmath>

using namespace std;

int calculateSum (int a, int b)
{
    return a + b;
}

int calculateProd (int a, int b)
{
    return a * b;
}

int calculateSqrt (int a)
{
    return sqrt(a);
}

void newNumbers (int &a, int &b)
{
    cout << "Enter x value : ";
    cin >> a;
    cout << "Enter y value : ";
    cin >> b;
}

bool exitProgram ()
{
    return true;
}

int main(void)
{
    bool finishCalculation = false;
    int x, y;
    char operation;
    
    cout << "Enter x value : ";
    cin >> x;
    cout << "Enter y value : ";
    cin >> y;

    while (!finishCalculation)
    {
        cout << "\nMENU:x = " << x << ", y = " << y << endl;
        cout << "Press \'s\' to calculate the sum." << endl;
        cout << "Press \'p\' to calculate the product." << endl;
        cout << "Press \'r\' to calculate the sqrt of x." << endl;
        cout << "Press \'n\' to enter new numbers." << endl;
        cout << "Press \'x\' to exit the program." << endl;
        cout << "Enter your option: ";
        cin >> operation;
        
        switch (operation)
        {
            case 's':
                cout << "The sum of " << x << " and " << y << " is:" << calculateSum(x, y) << endl;
                break;
            case 'p':
                cout << "The product of " << x << " and " << y << " is:" << calculateProd(x, y) << endl;
                break;
            case 'r':
                cout << "The sqrt of " << x << " is:" << calculateSqrt(x) << endl;
                break;
            case 'n':
                newNumbers(x, y);
                break;
            case 'x':
                cout << "Program will exit! See you soon ... " << endl;
                finishCalculation = exitProgram();
                break;
            default:
                cout << "Choosen option does not exit, please try again!" << endl;
        }
    }

    return 0;
}
