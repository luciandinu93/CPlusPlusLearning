/* A real and usable calculator
 *
 * Write a real interctive four function calculator.
 */

#include <iostream>

using namespace std;

int main(void)
{
    short unsigned int operation;
    double a, b;
    bool stopExecution = false;

    while (!stopExecution)
    {
        cout << "MENU: " << endl;
        cout << "0 - exit " << endl;
        cout << "1 - addition" << endl;
        cout << "2 - substraction" << endl;
        cout << "3 - multiplication" << endl;
        cout << "4 - division" << endl;
        cout << "Your choice : ";
        cin >> operation;

        switch (operation)
        {
            case 0 :
                stopExecution = true;
                break;
            case 1 :
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << a << " + " << b << " = " << a + b << endl;
                break;
            case 2:
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << a << " - " << b << " = " << a - b << endl;
                break;
            case 3:
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << a << " * " << b << " = " << a * b << endl;
                break;
            case 4:
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                while (b == 0)
                {
                    cout << "Error! b must be different from 0. \nb = ";
                    cin >> b;
                }
                cout << a << " / " << b << " = " << a / b << endl;
                break;
        }

    }


    return 0;
}
