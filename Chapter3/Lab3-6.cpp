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

int daysBetween(Date d1, Date d2)
{
    int daysBetween = 0;

    if(d1.year > d2.year)
        return -1;
    else if(d1.year >= d2.year && d1.month > d2.month)
        return -1;
    else if(d1.year >= d2.year && d1.month >= d2.month && d1.day > d2.day)
        return -1;

    daysBetween = dayOfYear(d2) - dayOfYear(d1);
    for(int i = d1.year; i < d2.year; i++)
    {
        if(isLeap(i))
            daysBetween += 366; // leap year
        else
            daysBetween += 365; // not leap year
    }
    return daysBetween;
}

int main(void)
{
    Date since, to;

    cout << "Enter first date (y m d):";
    cin >> since.year >> since.month >> since.day;
    cout << "Enter second date (y m d):";
    cin >> to.year >> to.month >> to.day;
    cout << daysBetween(since, to) << endl;

    return 0;
}
