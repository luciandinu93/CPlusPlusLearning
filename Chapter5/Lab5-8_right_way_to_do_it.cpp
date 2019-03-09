/* Credits to : https://github.com/Piikasooo */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

class Member
{
public:
	Member(int id, std::string name, int membership = 0);
	it Id() {return id;}
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
		throw invalid_argument("ID can't be <= 0");
	if(name.empty())
		throw invalid_argument("Name can't be empty");
	if(membership < 0)
		throw invalid_argument("Membership can't be < 0");
	
	this->id = id;
	this->name = name;
	this->membership = membership;
}

void Member::SetName(std::string name)
{
	if(name.empty())
		throw invalid_argument("Name can't be empty");
	this->name = name;
}

void Member::ExtendMembership(int membership)
{
	if(membership <= 0)
		throw invalid_argument("Can't extend membership by value <= 0");
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

int main(void)
{
	std::string command, name;
	int id, membership;
	vector<Member> members;
	istringstream iss;
	
	do
	{
		std::cout << "Enter a command: " << std::endl;
		std::geline(std::cin, command);
		iss.str(command);
		
		
		
	}while(command != "quit");
	
	return 0;
}