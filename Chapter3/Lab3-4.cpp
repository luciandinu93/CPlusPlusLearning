/* One step further: finding the lengths of months
 * Write function equipped with the following features:
 * -> its name is "monthLength"
 * -> it accepts two arguments of type int: year number, month number
 * -> it returns an int value which represents a length of specified month in a specified year 
 */

#include <iostream>

using namespace std;

bool isLeap(int year)
{
    if(year % 400 == 0)
        return 1;
    else if(year % 100 == 0)
        return 0;
    else if(year % 4 == 0)
        return 1;
    else
        return 0;
}

int monthLength(int year, int month)
{
    int daysOfLeapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysOfYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isLeap(year))
        return daysOfLeapYear[month - 1];
    else
        return daysOfYear[month - 1];
}

int main(void)
{
    for(int yr = 2000; yr < 2002; yr++)
    {
        for(int mo = 1; mo <= 12; mo++)
        {
            cout << monthLength(yr, mo) << " ";
        }
        cout << endl;
    }

    return 0;
}
