#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c, d;

    bool a_ok, b_ok, c_ok, d_ok;

    a_ok = false;
    b_ok = false;
    c_ok = false;
    d_ok = false;

    while (!(a_ok && b_ok && c_ok && d_ok))
    {
        cout << "Enter number \'a\' from ip address \"a.b.c.d\"" << endl;
        cin >> a;

        if (a > 0 && a < 256)
            a_ok = true;
        else
        {
            cout << "wrong number, try again!" << endl;
            continue;
        }
        
        cout << "Enter number \'b\' from ip address \"a.b.c.d\"" << endl;
        cin >> b;

        if (b > 0 && b < 256)
            b_ok = true;
        else
        {
            cout << "wrong number, try again!" << endl;
            continue;
        }

        cout << "Enter number \'c\' from ip address \"a.b.c.d\"" << endl;
        cin >> c;

        if (c > 0 && c < 256)
            c_ok = true;
        else
        {
            cout << "wrong number, try again!" << endl;
            continue;
        }

        cout << "Enter number \'d\' from ip address \"a.b.c.d\"" << endl;
        cin >> d;
        
        if (d > 0 && d < 256)
            d_ok = true;
        else
        {
            cout << "wrong number, try again!" << endl;
            continue;
        }
    }

    cout << a << "." << b << "." << c << "." << d << endl;

    return 0;
}
