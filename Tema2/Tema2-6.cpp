/* Write a program that generates a random number between 0 and 100 and then
 * ask the user to introduce numbers until the generated number is guessed.
 * For each mistake the user is informed that he must introduce a bigger or a smaller number
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void)
{
    int numberToBeGuessed, x;
    
    // initialize random seed
    srand (time(NULL));
    // generate a random number
    numberToBeGuessed = rand() % 101;
    
    cout << "Try to guess the number, is between 0 and 100!" << endl;
    cout << "Enter a number: ";
    cin >> x;

    while (x != numberToBeGuessed)
    {
        if (x < numberToBeGuessed)
        {
            cout << "Number is too small, try another one: ";
            cin >> x;
        }
        else
        {
            cout << "Number is too big, try another one: ";
            cin >> x;
        }
    }

    cout << "YES! You guessed it! The number is : " << numberToBeGuessed << endl;

    return 0;
}
