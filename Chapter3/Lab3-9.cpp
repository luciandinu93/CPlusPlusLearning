/* Modifying a function argument's value
 * 1. Name of function "increment"
 * 2. Returns void
 * 3. When invoked with one argument (int value), increments the variable by 1
 * 4. When invoked with two arguments (an int variable and int expression), it increments the variable by the expresion's value.
 */

#include <iostream>

using namespace std;

void increment(int &var)
{
    var++;
}

void increment(int &var, int i)
{
    var += i;
}

int main(void)
{
    int var = 0;

    for(int i = 0; i < 10; i++)
        if(i % 2)
            increment(var);
        else
            increment(var, i);
    cout << var << endl;

    return 0;
}
