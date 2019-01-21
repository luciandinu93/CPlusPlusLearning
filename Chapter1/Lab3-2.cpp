#include <iostream>

using namespace std;

int main(void)
{
    float pi = 3.14159265359;
    float x, y, x_square, pi_square, half;
    
    // reading value of x
    cout << "Enter value for x: ";
    cin >> x;

    // helping variable
    x_square = x * x;
    pi_square = pi * pi;
    half = 0.5;

    y = (x_square / (pi_square * (x_square + half))) *
        (1 + (x_square / (pi_square * (x_square - half) * (x_square - half))));

    // displaying the value of y
    cout << "y = " << y;

    return 0;
}
