#include <iostream>

using namespace std;

int main(void)
{
    int x, y;
    float result1, result2;
    float epsilon;

    epsilon = 0.000001;

    cout << "Enter value of x: " << endl;
    cin >> x;

    cout << "Entear value of y: " << endl;
    cin >> y;

    result1 = 1.0 / (float)x;
    result2 = 1.0 / (float)y;

    if (abs(result1 - result2) <= epsilon)
        cout << fixed << "Results are equal (by " << epsilon << " epsilon)" << endl;
    else
        cout << fixed << "Results are not equal (by " << epsilon << " epsilon)" << endl;

    return 0;
}
