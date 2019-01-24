/* Find the date of Easter
 *
 * 1. Divide year by 19 and find the remainder - assign it to a;
 * 2. Divide year by 4 and find the reminder - assign it to b;
 * 3. Divide year by 7 and find the reminder - assign it to c;
 * 4. Take a, multiply it by 19 add 4 divide by 30 and find the reminder - assign it to d;
 * 5. Divide (2b + 4c + 6d + 5) by 7 and find the reminde - assign it to e;
 * 6. Check the value of d+e;
 * 7. If it's less than 10, Easter falls on the (d+e+22) day of March;
 * 8. Otherwise it falls on the (d + e - 9) day of April;
 * 9. that's all!
 */

#include <iostream>

using namespace std;

int main(void)
{
    short int year, a, b, c, d, e;

    cout << "Enter year to find out the date of Easter: ";
    cin >> year;

    a = year % 19; 
    b = year % 4;
    c = year % 7;
    d = (a * 19 + 24) % 30;
    e = (2 * b + 4 * c + 6 * d + 5) % 7;
    if ( (d + e) < 10)
        cout << "Easter falls on the " << (d + e + 22) << " day of March";
    else
        cout << "Easter falls on the " << (d + e - 9) << " day of April";
    
    return 0;
}
