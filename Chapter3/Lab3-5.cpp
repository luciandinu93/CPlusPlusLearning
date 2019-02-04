/* Finding day of year */ 

#include <iostream>

using namespace std;

struct Date 
{
    int year;
    int month;
    int day;
};

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

int dayOfYear(Date date)
{
    int year = date.year;
    int month = date.month;
    int day = date.day;
    int dayNumber = 0;

    for(int i = 1; i <= month; i++)
    {
        if(i == month)
            dayNumber += day;
        else
            dayNumber += monthLength(year, i);
    }
    return dayNumber;
}

int main(void)
{
    Date d;
    
    cout << "Enter year mont day: ";
    cin >> d.year >> d.month >> d.day;
    cout << dayOfYear(d) << endl;

    return 0;
}
