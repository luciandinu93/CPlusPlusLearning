/* Old problems, new methods: functions
 * Write a function equipped with the following features:
 * 1. name : isLeap
 * 2. one argument of type int representing the year
 * 3. return bool value: true if the year is leap and false otherwise
 * 4. it should be mute! write nothign to output
 */

#include <iostream>

using namespace std;

bool isLeap(int year)
{
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year % 4 == 0)
        return true;
    else
        return false;
}

int main(void)
{
    for(int yr = 1995; yr < 2017; yr++)
        cout << yr << " -> " << isLeap(yr) << endl;

    return 0;
}
