/* How find a weekeday for any (past of future) date?
 * Algorithm -> Zeller's congruence
 * Three values:
 * -> year number (int)
 * -> month number (int 1 - 12)
 * -> day number (int 1 - it depends)
 *
 * Zeller's congurence algorithm:
 * 1. Decrease month number by 2;
 * 2. If month number becomes less than 0, increment it by 12 and decrement year by 1;
 * 3. take month number and mutiply it by 83 and divide it by 32;
 * 4. add day number to month
 * 5. add year number to month
 * 6. add year/4 to month
 * 7. substract year/100 from month;
 * 8. add year/400 to month
 * 9. find the reminder of dividing month by 7
 * 10. congrats! a weekday number is ready for you ! 0 - sunday 1- monday and so on;
 */

#include <iostream>
#include <string>

using namespace std;

int main (void)
{
    short int year, month, day;
    string weekday;

    cout << "Find weekeday!" << endl;
    cout << "Enter day number: ";
    cin >> day;
    cout << "Enter month number: ";
    cin >> month;
    cout << "Enter yearn number: ";
    cin >> year;
    
    month -= 2; // decrease month number by 2
    if (month < 0) // if month < 0
    {
        month += 12;
        year--;
    }
    month = month * 83 / 32; // take month number and multiply it by 83 and divide it by 32
    month += day; // add day number to month
    month += year; // add year number to month
    month += year/4; // add year/4 to month
    month -= year/100; // substract year 100 from month
    month += year/400; // add year/400 to month
    month %= 7; 

    switch (month)
    {
        case 0:
            cout << "The weekday of " << day << "." << month << "." << year << " is Sunday!" << endl;
            break;
        case 1:
            cout << "The weekday of " << day << "." << month << "." << year << " is Monday!" << endl;
            break;
        case 2:
            cout << "The weekday of " << day << "." << month << "." << year << " is Tuesday!" << endl;
            break;
        case 3:
            cout << "The weekday of " << day << "." << month << "." << year << " is Wednesday!" << endl;
            break;
        case 4:
            cout << "The weekday of " << day << "." << month << "." << year << " is Thursday!" << endl;
            break;
        case 5:
            cout << "The weekday of " << day << "." << month << "." << year << " is Friday!" << endl;
            break;
        case 6:
            cout << "The weekday of " << day << "." << month << "." << year << " is Saturday!" << endl;
            break;
        default:
            cout << "Introduced date is wrong!" << endl;

    }

    return 0;
}
