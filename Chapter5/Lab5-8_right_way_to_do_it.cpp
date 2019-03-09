/* Credits to : https://github.com/Piikasooo */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

class Member
{
public:
	Member(int id, std::string name, int membership);
	int Id() {return id;}
	std::string Name() {return name;}
	int Membership() {return membership;}
	void SetName(std::string name);
	void ExtendMembership(int membership);
	void CancelMembership(void);
	void PrintMember(void);
private:
	int id;
	std::string name;
	int membership;
};

Member::Member(int id, std::string name, int membership = 0)
{
	if(id <= 0)
		throw std::invalid_argument("ID can't be <= 0");
	if(name.empty())
		throw std::invalid_argument("Name can't be empty");
	if(membership < 0)
		throw std::invalid_argument("Membership can't be < 0");
	
	this->id = id;
	this->name = name;
	this->membership = membership;
}

void Member::SetName(std::string name)
{
	if(name.empty())
		throw std::invalid_argument("Name can't be empty");
	this->name = name;
}

void Member::ExtendMembership(int membership)
{
	if(membership <= 0)
		throw std::invalid_argument("Can't extend membership by value <= 0");
	this->membership += membership;
}

void Member::CancelMembership(void)
{
	this->membership = 0;
}

void Member::PrintMember(void)
{
	std::cout << "Member " << id << ": " << name << ", subscription valid for " << membership << " months" << std::endl;
}

bool MemberWithThisIdExists(std::vector<Member> members, int id)
{
	std::vector<Member>::iterator member;
	for(member = members.begin(); member < members.end(); ++member)
	{
		if(member->Id() == id)
		{
			return true;
		}
	}
	return false;
}

void lookMembers(std::vector<Member> members)
{
	std::vector<Member>::iterator member;
	for(member = members.begin(); member < members.end(); ++member)
	{
		member->PrintMember();
	}
	std::cout << std::endl;
}

void removeMemberById(std::vector<Member> &members, int id)
{
	std::vector<Member>::iterator member;
	for(member = members.begin(); member < members.end(); ++member)
	{
		if(member->Id() == id)
		{
			members.erase(member);
			return;
		}
	}
	
	throw std::invalid_argument("This member does not exists!");
}

Member& findMemberById(std::vector<Member> &members, int id)
{
	std::vector<Member>::iterator member;
	for(member = members.begin(); member < members.end(); ++member)
	{
		if(member->Id() == id)
		{
			return *member;
		}
	}
	
	throw std::invalid_argument("This member does not exists!");
}

int main(void)
{
	std::string command, name;
	int id, membership;
	std::vector<Member> members;
	std::istringstream iss;
	
	do
	{
		std::cout << "Enter a command: " << std::endl;
		std::getline(std::cin, command);
		iss.str(command);
		
		try
		{
			iss >> command;
			if(command == "create")
			{
				iss >> id;
				if(iss.fail())
					throw std::invalid_argument("You did not entered an ID");
				if(MemberWithThisIdExists(members, id))
					throw std::invalid_argument("Member with this ID already exists.");
				std::getline(iss, name);
				members.push_back(Member(id, name));
				lookMembers(members);
			}
			else if(command == "delete")
			{
				iss >> id;
				if(iss.fail())
				{
					throw std::invalid_argument("You did not entered an ID");
				}
				removeMemberById(members, id);
				lookMembers(members);
			}
			else if(command == "extend")
			{
				iss >> id;
				if(iss.fail())
					throw std::invalid_argument("You did not entered an ID");
				iss >> membership;
				if(iss.fail())
					throw std::invalid_argument("You did not entered a membership");
				findMemberById(members, id).ExtendMembership(membership);
				lookMembers(members);
			}
			else if(command == "cancel")
			{
				iss >> id;
				if(iss.fail())
					throw std::invalid_argument("You did not entered an ID");
				findMemberById(members, id).CancelMembership();
				lookMembers(members);
			}
		}
		catch(const std::exception& e)
		{
			std::cout << "Cannot perform this operation, because: " << e.what() << std::endl << std::endl;
		}
		
		iss.clear();
		
	}while(command != "quit");
	
	return 0;
}