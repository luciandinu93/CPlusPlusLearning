#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    float a = 2.3;
    float b = 2.3;
    float c = 2.123456;
    float d = 2.123456;
    float e = 2.123456;

    // display 2.3
    cout << a << endl;
    
    // display 2.30
    cout << fixed << setprecision(2) << b << endl;
    
    // display 2.123456
    cout << fixed << setprecision(6) << c << endl;
    
    // display 2.12
    cout << fixed << setprecision(2) << d << endl;
    
    // display 2
    cout << (int)e << endl;

    return 0;
}
