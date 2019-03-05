/*Flight booking system part3 */

#include <iostream>
#include <string>
#include <exception>

class FlightBooking
{
public:
    FlightBooking(int id, int capacity, int reserved);
	FlightBooking();
	~FlightBooking();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
	FlightBooking createFB(int capacity);
	FlightBooking deleteFB();
	int getId() {return id;}
	static int getFligthsNo() {return flights_no;}
private:
    int id;
    int capacity;
    int reserved;
	static int flights_no;
};

int FlightBooking::flights_no = 0; // initializer

FlightBooking::FlightBooking()
{
	id = 0;
	capacity = 0;
	reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;

    if(int(((float)reserved/capacity) * 100) <= 105 && reserved >= 0)
    {
        this->reserved = reserved;
		flights_no++;
    }
    else if(reserved < 0)
    {
        this->reserved = 0;
		flights_no++;
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

bool id_exists(FlightBooking *booking, int id)
{
	bool exists = false;
	for(int i = 0; i < FlightBooking::getFligthsNo(); i++)
	{
		if(booking[i].getId() == id)
			exists = true;
	}

	return (exists) ? true : false;
}

void startCommand(FlightBooking *booking, std::string command, int id, int seats)
{
	if(command.compare("create") == 0)
	{
		booking[FlightBooking::getFligthsNo()] = FlightBooking(id, seats, 0);
	}
	else if(command.compare("add") == 0)
	{
		if(id_exists(booking, id))
			booking[id].reserveSeats(seats);
		else
			std::cout << "The fligth with the required id does not exists" << std::endl;
	}
	else if(command.compare("cancel") == 0)
	{
		if(id_exists(booking, id))
			booking[id].cancelReservations(seats);
		else
			std::cout << "The fligth with the required id does not exists" << std::endl;
	}
	else
	{
		std::cout << "ERROR:Unknown command!" << std::endl;
	}
}

bool to_int(std::string str, int &number)
{
	try
	{
		number = std::stoi(str);
		return true;
	}
	catch (const std::invalid_argument& ia)
	{
		std::cout << "ERROR:The argument is invalid." << std::endl;
		return false;
	}
	catch (const std::out_of_range& ofr)
	{
		std::cout << "ERROR:The argument is invalid." << std::endl;
		return false;
	}
}

void processCommand(FlightBooking *booking, std::string command)
{
	int space_count = 0, space_pos, id, cap, seats;
	std::string action, number1, number2;
	bool id_exists = false;

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
	else if(space_count == 1)
	{
		if((command.substr(0, space_pos)).compare("delete") == 0)
		{
			action = command.substr(0, space_pos);
			number1 = command.substr(space_pos+1);

			if(to_int(number1, id))
			{
				for(int i = 0; i < FlightBooking::getFligthsNo(); i++)
				{
					if(booking[i].getId() == id)
						id_exists = true;
				}

				if(id_exists)
				{
					for(int j = i; j < FlightBooking::getFligthsNo(); j++)
                    {
                        booking[j] = booking[j+1];
                    }
                    FlightBooking::getFligthsNo()--;
				}
				else
				{
					std::cout << "The fligth with the required id does not exists" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid command, try again!" << std::endl;
				std::cout << "The second parameter must be an int!" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid command, try again!" << std::endl;
		}
	}
	else if(space_count > 2)
	{
		std::cout << "Invalid command, try again!" << std::endl;
	}
	else
	{
		number2 = command.substr(space_pos+1);
		command.erase(space_pos);
		space_pos = command.find(' ');
		action = command.substr(0, space_pos);
		number1 = command.substr(space_pos+1);

		// DEBUG
		std::cout << "action: ." << action << ". number1 ." << number1 << ". number 2 ." << number2 << "." << std::endl;

		if(to_int(number1, id) && to_int(number2, seats))
		{
			startCommand(booking, action, id, seats);
		}
		else
		{
			std::cout << "Invalid command, try again!" << std::endl;
			std::cout << "The two numeral parameters must be int!" << std::endl;
		}
	}
}

int main(void)
{
	FlightBooking booking[10];
    int reserved = 0;
    int capacity = 0;

	std::string command = "";
	while(command != "quit")
	{
		if(FlightBooking::getFligthsNo() != 0)
			for(int i = 0; i < FlightBooking::getFligthsNo(); i++)
			{
				booking[i].printStatus();
			}

		std::cout << "What would you like to do? " << std::endl;
		std::cout << "\tcreate[id][cap]" << std::endl;
		std::cout << "\tdelete[id]" << std::endl;
		std::cout << "\tadd[id][n]" << std::endl;
		std::cout << "\tcancel[id][n]" << std::endl;
		std::cout << "\tquit" << std::endl;
		std::cout << "Your option: ";

		std::getline(std::cin, command);
		processCommand(booking, command);
		std::cout << "-------------------------------------------------" << std::endl;
	}

	return 0;
}

