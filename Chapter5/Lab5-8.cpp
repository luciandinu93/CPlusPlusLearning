/* Gym membership management system 
 * Build a program that will manage gym subscriptions:
 * The data to be stored for each memeber:
 * - their user ID
 * - their name
 * - for how many months the membership is valid
 * Should allow following commands:
 * - create[id][name] 
 * - delete[id]
 * - extend[id]
 * - cancel[id]
 * - quit
*/

#include <iostream>
#include <string>

class GymMembership
{
public:
	GymMembership(int id, std::string name);
	GymMembership(void);
	~GymMembership(void);
	void extend(int months);
	void cancel(void);
	void display(void);
	int getId() {return this->id;}
	static int get_memberships_no() {return memberships_no;}
private:
	int id;
	std::string name;
	int months;
	static int memberships_no;
};

int GymMembership::memberships_no = 0; // initialize

GymMembership::GymMembership(int id, std::string name)
{
	this->id = id;
	this->name = name;
	this->months = 0;
	GymMembership::memberships_no++;
}

GymMembership::GymMembership(void)
{
	this->id = 0;
	this->name = "";
	this->months = 0;
}

GymMembership::~GymMembership(void)
{
	memberships_no--;
	std::cout << "The memeber " << getId() << " has been destroyed" << std::endl;
}

void GymMembership::extend(int months)
{
	this->months = months;
}

void GymMembership::cancel(void)
{
	this->months = 0;
}

void GymMembership::display(void)
{
	std::cout << "Member " << getId() << " : " << this->name << ", subscription valid for " << 
			this->months << " months" << std::endl;
}

// TO DO
int spaces_nr(std::string command)
{
}

int main(void)
{
	GymMembership gym_mem[10];
	std::string command, action, name, id, n;
	int space_index1, space_index2, i_id, i_n;
	
	while(true)
	{
		if(GymMembership::get_memberships_no() == 0)
			std::cout << "No members in the system" << std::endl;
		
		std::cin.ignore();
		std::getline(std::cin, command);
		
		std::cout << "Command: " << command << std::endl;
		
		if(command.compare("quit") == 0)
			break;
		else
		{
			if(spaces_nr(command) == 0)
			{
				std::cout << "ERROR:Unknown command" << std::endl;
			}
			else if(spaces_nr(command) == 1)
			{
				space_index1 = command.find(' ');
				
				action = command.substr(0, space_index1);
				std::cout << "Action: ." << action << "." << std::endl;
				
				id = command.substr(space_index1+1);
				std::cout << "Id: ." << id << "." << std::endl;
			}
		}
	}
	
	return 0;
}

