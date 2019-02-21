/*Flight booking system part2 
 * Constructor will allow max of 105% reserved seats
 * If reserved seats < 0 set it to 0
 * Provide interface for user to :
 * 1. add [n], will try to add n reservations to the flight
 * 2. cancel [n], will try to cancel n reservations for the flight
 * 3. if operation fails, it should provide the following information : "Cannot perform this operation"
 * 4. the command quit will stop execution of program
 */

#include <iostream>
#include <string>

class FlightBooking
{
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;

    if(int(((float)reserved/capacity) * 100) <= 105 && reserved >= 0)
    {
        this->reserved = reserved;
    }
    else if(reserved < 0)
    {
        this->reserved = reserved;
    }
    else
    {
        this->reserved = 1.05 * capacity;
    }
}

void FlightBooking::printStatus(void)
{
    std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " <<
        "(" << (int)((float)reserved/capacity * 100) << "%) seats reserved";
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
    int limit_seats = 1.05 * capacity;

    if(number_of_seats + reserved <= limit_seats)
    {
        reserved = reserved + number_of_seats;
        return true;
    }
    return false;
}

bool FlightBooking::cancelReservations(int number_of_seats)
{
    if(reserved - number_of_seats >= 0)
    {
        reserved = reserved - number_of_seats;
        return true;
    }
    return false;
}

int main(void)
{
    int reserved = 0;
    int capacity = 0;

    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats:";
    std::cin >> reserved;

    std::cout << std::endl;

    FlightBooking booking(1, capacity, reserved);

    std::string command = "";
    while(command != "quit")
    {
        booking.printStatus();
        std::cout << "What would you like to do?: ";
        std::getline(std::cin, command);
        std::cout << command << ". " << std::endl;
    }
}

