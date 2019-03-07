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

struct command_struct
{
	std::string action;
	std::string name;
	int id;
	int n;
};

void process(command_struct &cstr, std::string command, bool &flag)
{
	int space_index, space_index2;
	
	space_index = command.find(' ');
	
	if(space_index == std::string::npos)
	{
		flag = false;
		std::cout << "ERROR:Unknown command!" << std::endl;
	}
	else
	{
		cstr.action = command.substr(0, space_index);
		
		if(cstr.action == "create")
		{
			if(command.find(' ', space_index+1) != std::string::npos)
			{
				space_index2 = command.find(' ', space_index+1);
				try
				{
					cstr.id = stoi(command.substr(0, space_index2));
					cstr.name = command.substr(space_index2+1);
					flag = true;
				}
				catch
				{
					std::cout << "ERROR:ID can not be converted to INT!" << std::endl;
					flag = false;
				}
			}
			else
			{
				std::cout << "ERROR:No ID provided!" << std::endl;
				flag = false;
			}
			
		}
		else if(cstr.action == "delete")
		{
			// TO DO
		}
		else if(cstr.action == "extend")
		{
			// TO DO
		}
		else if(cstr.action == "cancel")
		{
			// TO DO
		}
		else
		{
			flag = false;
			std::cout << "ERROR:Unknown command!" << std::endl;
		}
	}
}

int main(void)
{
	GymMembership gym_mem[10];
	std::string command, action, name, id, n;
	int space_index, i_id, i_n;
	bool flag = false;
	
	while(true)
	{
		if(GymMembership::get_memberships_no() == 0)
			std::cout << "No members in the system" << std::endl;
		
		std::getline(std::cin, command, flag);
		
		std::cout << "Command: " << command << std::endl;
		
		if(command.compare("quit") == 0)
			break;
		else
		{
			command_struct cstr;
			process(cstr, command);
			if(flag)
				start(cstr);
		}	
	}
	return 0;
}

