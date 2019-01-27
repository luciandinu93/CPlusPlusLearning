/* Simple vector manipulations
 * Rotate vector to the right
 */

#include <iostream>

using namespace std;

int main(void)
{
    int vector1[7] = {4, 7, 2, 8, 1, 3, 0};
    int vector2[7];

    for(unsigned short int i = 0; i < 7; i++)
    {
        if (i == 0)
            vector2[i] = vector1[6];
        else
            vector2[i] = vector1[i-1];
    }
    for(unsigned short int i = 0; i < 7; i++)
        cout << vector2[i] << ' ';
    cout << endl;

    return 0;
}
