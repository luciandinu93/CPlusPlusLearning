/* Vectors and pointers : first try*/

#include <iostream>

using namespace std;

int main(void)
{
    int vector[] = {3, -5, 7, 10, -4, -14, 14, 5, 2, -13};
    int n = sizeof(vector) / sizeof(vector[0]);
    int* vecPtr = vector;
    int min = *vecPtr;

    for (int i = 0; i < n; i++)
    {
        *vecPtr++;
        if (min > *vecPtr)
            min = *vecPtr;
    }

    cout << "Min = " << min;

    return 0;
}
