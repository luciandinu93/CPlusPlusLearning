/* Leap year = 366 days 
 * Common year = 365 days
 *
 * if the year number isn't divisible by 4, it is a common year
 * otherwise, if the year number isn't divisible by 100, it is a leap year
 * otherwise, if the year number isn't divisible by 400, it is a common year
 * otherwise, it is a leap year
 *
 * To do:
 * Test if a year is Leap year or CommonYear
 */
#include <iostream>

using namespace std;

int main(void)
{
    int year;
    bool isGregorianYear;

    isGregorianYear = false;
    
    while (!isGregorianYear)
    {
        cout << "Enter a year: ";
        cin >> year;

        if (year >= 1582)
            isGregorianYear = true;
        else
            cout << "Please enter a year later than 1582." << endl;
    }
    
    if (year % 4 != 0)
        cout << "Common year" << endl;
    else if (year % 100 != 0)
        cout << "Leap year" << endl;
    else if (year % 400 != 0)
        cout << "Common year" << endl;
    else
        cout << "Leap year";

    return 0;
}
