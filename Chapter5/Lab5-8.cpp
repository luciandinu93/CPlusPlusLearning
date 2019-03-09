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

#define MAX_PERS 10

class GymMembership
{
public:
	GymMembership(int id, std::string name);
	GymMembership(void);
	void extend(int months);
	void cancel(void);
	void display(void);
	int getId() {return this->id;}
private:
	int id;
	std::string name;
	int months;
};

GymMembership::GymMembership(int id, std::string name)
{
	this->id = id;
	this->name = name;
	this->months = 0;
	// Debug only
	// std::cout << "The memeber " << id << " named " << name << " has been created!" << std::endl;
}

GymMembership::GymMembership(void)
{
	this->id = 0;
	this->name = "";
	this->months = 0;
}

void GymMembership::extend(int months)
{
	this->months += months;
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

// structure for commands
struct command_struct
{
	std::string action;
	std::string name;
	int id;
	int n;
};

bool id_exists(GymMembership *gym_mem, int id)
{
	for(int i = 0; i < MAX_PERS; i++)
	{
		if(gym_mem[i].getId() == id)
			return true;
	}
	
	return false;
}

// Debug only
void display_command_struc(command_struct &cstr)
{
	std::cout << "The created struct is : " << std::endl;
	std::cout << "Action: ." << cstr.action << "." << std::endl;
	std::cout << "Id: ." << cstr.id << "." << std::endl;
	std::cout << "Name: ." << cstr.name << "." << std::endl;
	std::cout << "n: ." << cstr.n << "." << std::endl;
	
}

void process(GymMembership *gym_mem, command_struct &cstr, std::string command, bool &flag)
{
	int space_index, space_index2;
	std::string id, n;
	
	space_index = command.find(' ');
	
	if(space_index == std::string::npos)
	{
		flag = false;
		std::cout << "ERROR:Unknown command!" << std::endl;
	}
	else
	{
		cstr.action = command.substr(0, space_index); // Get the action
		
		if(cstr.action == "create")
		{
			if(command.find(' ', space_index+1) != std::string::npos)
			{
				space_index2 = command.find(' ', space_index+1);
				try
				{
					id = command.substr(space_index+1, space_index2 - space_index);
					cstr.id = stoi(id);
					cstr.name = command.substr(space_index2+1);
					cstr.n = 0;
					if(cstr.id == 0)
					{
						std::cout << "ERROR:ID = 0 is not a valid ID: " << std::endl;
						flag = false;
					}
					else if(id_exists(gym_mem, cstr.id))
					{
						std::cout << "ERROR:This ID is already taken by another person: " << std::endl;
						flag = false;
					}
					else
					{
						flag = true;
					}
				}
				catch(...)
				{
					std::cout << "ERROR:ID can not be converted to INT!" << std::endl;
					flag = false;
				}
			}
			else
			{
				std::cout << "ERROR:No ID or name provided!" << std::endl;
				flag = false;
			}
			
		}
		else if(cstr.action == "delete")
		{
			if(command.find(' ', space_index+1) != std::string::npos)
			{
				std::cout << "ERROR:The format of delete command is not valid!" << std::endl;
			}
			else
			{
				try
				{
					id = command.substr(space_index+1);
					cstr.id = stoi(id);
					cstr.name = "";
					cstr.n = 0;
					if(id_exists(gym_mem, cstr.id))
					{
						flag = true;
					}
					else
					{
						std::cout << "ERROR:This ID does not exit! Cannot delete : " << std::endl;
						flag = false;
					}
				}
				catch(...)
				{
					std::cout << "ERROR:ID can not be converted to INT!" << std::endl;
					flag = false;
				}
			}
		}
		else if(cstr.action == "extend")
		{
			if(command.find(' ', space_index+1) != std::string::npos)
			{
				space_index2 = command.find(' ', space_index+1);
				try
				{
					id = command.substr(space_index+1, space_index2 - space_index);
					n = command.substr(space_index2+1);
					cstr.id = stoi(id);
					cstr.name = "";
					cstr.n = stoi(n);
					if(id_exists(gym_mem, cstr.id))
					{
						flag = true;
					}
					else
					{
						std::cout << "ERROR:This ID does not exist: " << std::endl;
						flag = false;
					}
				}
				catch(...)
				{
					std::cout << "ERROR:ID can not be converted to INT!" << std::endl;
					flag = false;
				}
			}
			else
			{
				std::cout << "ERROR:No ID or months provided!" << std::endl;
				flag = false;
			}
		}
		else if(cstr.action == "cancel")
		{
			if(command.find(' ', space_index+1) != std::string::npos)
			{
				std::cout << "ERROR:No ID or months provided!" << std::endl;
				flag = false;
			}
			else
			{
				space_index2 = command.find(' ', space_index+1);
				try
				{
					id = command.substr(space_index+1, space_index2 - space_index);
					n = command.substr(space_index2+1);
					cstr.id = stoi(id);
					cstr.name = "";
					cstr.n = 0;
					if(id_exists(gym_mem, cstr.id))
					{
						flag = true;
					}
					else
					{
						std::cout << "ERROR:This ID does not exist: " << std::endl;
						flag = false;
					}
				}
				catch(...)
				{
					std::cout << "ERROR:ID can not be converted to INT!" << std::endl;
					flag = false;
				}
			}
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
	GymMembership gym_mem[MAX_PERS];
	std::string command, action, name, id, n;
	std::string line(50 , '-');
	int space_index, i_id, i_n, members = 0;
	bool flag = false;
	
	while(true)
	{
		if(members == 0)
		{
			std::cout << "No members in the system" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << line << std::endl;
			for(int i = 0; i < members; i++)
				gym_mem[i].display();
			std::cout << line << std::endl;
			std::cout << std::endl;
		}
		
		std::getline(std::cin, command);
		
		std::cout << "Command: " << command << std::endl;
		
		if(command.compare("quit") == 0)
			break;
		else
		{
			command_struct cstr;
			process(gym_mem, cstr, command, flag);
			if(flag)
			{
				// Debug only
				// display_command_struc(cstr);
				if(cstr.action == "create")
				{
					if(members+1 < MAX_PERS)
					{
						gym_mem[members] = GymMembership(cstr.id, cstr.name);
						members++;
					}
					else
					{
						std::cout << "ERROR:You can not add another membership! List is FULL!" << std::endl;
					}
					
				}
				else if(cstr.action == "delete")
				{
					for(int i = 0; i < MAX_PERS; i++)
					{
						if(gym_mem[i].getId() == cstr.id)
						{
							gym_mem[i] = gym_mem[i+1];
						}
					}
					gym_mem[members-1] = GymMembership();
					members--;
				}
				else if(cstr.action == "extend")
				{
					for(int i = 0; i < MAX_PERS; i++)
					{
						if(gym_mem[i].getId() == cstr.id)
						{
							gym_mem[i].extend(cstr.n);
						}
					}
				}
				else if(cstr.action == "cancel")
				{
					for(int i = 0; i < MAX_PERS; i++)
					{
						if(gym_mem[i].getId() == cstr.id)
						{
							gym_mem[i].cancel();
						}
					}
				}
				else
				{
					std::cout << "ERROR:Unknown command!" << std::endl;
				}
			}
				
		}	
	}
	return 0;
}

