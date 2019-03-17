/* Polymorphism part 2 */

#include <iostream>
#include <string>
#include <cmath>

class Piece
{
public:
	Piece() {this->x_int = 1; this->y_char = 'b';}
	void displayPosition(void);
	virtual bool check(char, int);
	virtual std::string getType(void);
protected:
	// position
	int x_int;
	char y_char;
};

class Man : public Piece
{
	bool check(char, int);
	std::string getType(void);
};

class King : public Piece
{
	bool check(char, int);
	std::string getType(void);
};

void Piece::displayPosition(void)
{
	std::cout << "Position of the piece is : *" << this->y_char << " " << this->x_int << "*" << std::endl;
}

bool Piece::check(char y, int x)
{
	std::cout << "virtual function" << std::endl;
	return false;
}

std::string Piece::getType(void)
{
	return "Piece";
}

bool King::check(char y, int x)
{
	if(y < 'a')
		throw "Invalid position";
	if(x < 1)
		throw "Invalid position";
	if(y_char - y == 0 != x_int - x == 0)
		return true;
	
	return false;
}

std::string King::getType(void)
{
	return "King";
}

bool Man::check(char y, int x)
{
	if(y < 'a')
		throw "Invalid position";
	if(x < 1)
		throw "Invalid position";
	if(std::abs(y_char - y) == std::abs(x_int - x))
		return true;
	
	return false;
}

std::string Man::getType(void)
{
	return "Man";
}

void move(Piece* p, char y, int x)
{
	if(p->check(y, x))
	{
		std::cout << "Piece of type " << p->getType() << " can be moved at position *" << y << " " << x << "*" << std::endl;
	}
	else
	{
		std::cout << "Piece of type " << p->getType() << " can not be moved at position *" << y << " " << x << "*" << std::endl;
	}
}
int main(void)
{
	Piece *k = new King;
	Piece *m = new Man;

	// Positive test
	move(k, 'f', 1);
	move(m, 'e', 4);
	
	std::cout << std::endl;
	
	// Negative test
	move(k, 'e', 2);
	move(m, 'd', 6);

	delete k;
	delete m;
	
	return 0;
}