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
#include <exception>

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
        this->reserved = 0;
    }
    else
    {
        std::cout << "Can not perform this operation!" << std::endl;
		throw 1;
	}
}

void FlightBooking::printStatus(void)
{
    std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " <<
        "(" << (int)((float)reserved/capacity * 100) << "%) seats reserved" << std::endl;
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
    int limit_seats = 1.05 * capacity;

    if(number_of_seats + reserved <= limit_seats)
    {
        reserved = reserved + number_of_seats;
        return true;
    }
	else
	{
		std::cout << "Can not perform this operation!" << std::endl;
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
	else
	{
		std::cout << "Can not perform this operation!" << std::endl;
	}
    return false;
}

void startCommand(FlightBooking &booking, std::string command, int seats)
{
	if(command.compare("add") == 0)
	{
		booking.reserveSeats(seats);
	}
	else if(command.compare("cancel") == 0)
	{
		booking.cancelReservations(seats);
	}
	else
	{
		std::cout << "ERROR:Unknown command!" << std::endl;
	}
}

void processCommand(FlightBooking &booking, std::string command)
{
	int space_count = 0, space_pos, num;
	std::string action, number;
	
	for(int i = 0; i < command.length(); i++)
	{
		if(command[i] == ' ')
		{
			space_count++;
			space_pos = i;
		}
	}
	
	if(space_count == 0 && command.compare("quit") == 0)
	{
		std::cout << "The program will exit!" << std::endl;
	}		
	else if(space_count == 0)
	{
		std::cout << "Invalid command, try again!" << std::endl;
	}
	else if(space_count > 1)
	{
		std::cout << "Invalid command, try again!" << std::endl;
	}
	else
	{
		action = command.substr(0, space_pos);
		number = command.substr(space_pos+1);
		
		try
		{
			num = std::stoi(number);
			// use command
			startCommand(booking, action, num);
		}
		catch (const std::invalid_argument& ia)
		{
			std::cout << "ERROR:The argument is invalid." << std::endl;
		}
		catch (const std::out_of_range& ofr)
		{
			std::cout << "ERROR:The argument is out of range." << std::endl;
		}
	}
}

int main(void)
{
    int reserved = 0;
    int capacity = 0;

    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;
	
    std::cout << std::endl;
	std::cin.ignore(); // ignore \n char from the buffer
	try
	{
		FlightBooking booking(1, capacity, reserved);

		std::string command = "";
		while(command != "quit")
		{
			booking.printStatus();
			std::cout << "What would you like to do? (add \'x\' or cancel \'x\'): ";
			
			std::getline(std::cin, command);
			processCommand(booking, command);
		}
	}
	catch(int e)
	{
		return 1;
	}
    
	return 0;
}

