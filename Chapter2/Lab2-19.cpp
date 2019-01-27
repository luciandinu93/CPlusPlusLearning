/* Collecting banknotes
 *
 * 50 plussar
 * 20 plussar
 * 10 plussar
 * 5 plussar
 * 1 plussar
 *
 * Write a driver that find the minimal number of banknotes needed to deliver any amunt of money to the client.
 */

#include <iostream>

using namespace std;

int main(void)
{
    int requestedMoney;
    unsigned short int i, banknotes[5] = {50, 20, 10, 5, 1};
    
    i = 0;

    cout << "How much money do you request : ";
    cin >> requestedMoney;

    while (requestedMoney)
    {
        if (requestedMoney - banknotes[i] >= 0)
        {
            requestedMoney = requestedMoney - banknotes[i];
            cout << banknotes[i] << ' ';
        }
        else
            i++;
    }

    return 0;
}
