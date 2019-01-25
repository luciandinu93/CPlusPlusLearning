/* Collatz's hypothesis
 *
 * 1. take any non negative and non zero integer number and name it c0;
 * 2. it it's even evaluate a new c0 as c0 / 2
 * 3. otherwise, if it's odd, evaluate a new c0 as 3 * c0 + 1
 * 4. c0 != 1 skip to point 2
 */

#include <iostream>

using namespace std;

int main(void)
{
    long int c0;
    int counter;
    bool nr_ok;

    counter = 0;
    nr_ok = false;

    while(!nr_ok)
    {
        cout << "Enter a positive number:";
        cin >> c0;
        if (c0 > 0)
        {
            nr_ok = true;
        }
        else
        {
            cout << "Number is invalid.Try again!" << endl;
        }
    }

    while (c0 != 1)
    {
        if (c0 % 2 == 0)
        {
            c0 = c0 / 2;
            cout << c0 << endl;
            counter++;
        }
        else
        {
            c0 = 3 * c0 + 1;
            cout << c0 << endl;
            counter++;
        }
    }

    cout << "steps = " << counter << endl;

    return 0;
}
