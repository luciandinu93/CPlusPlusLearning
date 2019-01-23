/* Ask the user to introduce 10 numbers, save them into an array and then
 * display only the items bigger than a specified value from keyboard.
 */

#include <iostream>

using namespace std;

int main(void)
{
    int vector[10], x;
    unsigned char k; // counter

    k = 0;

    cout << "Introduceti 10 numere aleatoare... " << endl << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ".Introduceti un numar aleator: ";
        cin >> vector[i];
    }   

    cout << "Introduceti o valoare de referinta... " << endl << endl;
    cin >> x;

    cout << "Numerele mai mari decat " << x << " sunt: " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (vector[i] > x)
        {
            cout << vector[i] << " ";
            k++;
        }
    }

    if (k == 0)
    {
        cout << "nu s-au gasit numere introduse mai mari decat " << x << endl;
    }

    return 0;
}
