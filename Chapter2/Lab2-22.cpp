/* Structure of time or time of structure
 * Declare a structure for handling the time of day with an accuracy of one minute.
 * Declare a variable of previously declared structure type and write a code for asking two values
 * -> hours
 * -> minutes
 * Check input
 * Input an int value and assume that the number is of minutes for an event
 * Display the time in format "HH:MM";
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Time
{
    string hour;
    string minute;
};

int main(void)
{
    Time time;
    unsigned short int hour_int, minute_int, eventTime, eventHours, eventMinutes;

    cout << "Enter the hours time: ";
    cin >> time.hour;

    hour_int = atoi(time.hour.c_str()); 
   
    while (hour_int < 0 || hour_int > 23)
    {
        cout << "Enter the hours time: ";
        cin >> time.hour;
    }

    cout << "Enter the minutes time:";
    cin >> time.minute;

    minute_int = atoi(time.minute.c_str());

    while (minute_int < 0 || minute_int > 59)
    {
        cout << "Enter the minutes time:";
        cin >> time.minute;
    }
    
           
    cout << "Enter number of minutes for one event:";
    cin >> eventTime;

    if (eventTime + minute_int > 59)
    {
        eventHours = eventTime / 60;
        while (eventHours > 23)
        {
            eventHours -= 24;
        }
        eventMinutes = eventTime - (eventHours * 60);
        
        if (eventMinutes + minutes_int > 59)
        {
            hours
        }

    }

    cout << hour_int << ":" << minute_int << endl;

    return 0;
}
