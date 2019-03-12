/* Polymorphism part 1 */

#include <iostream>

class BaseDraw
{
public:
	virtual void Draw() {std::cout << "BaseDraw:\n /\\";}
};

class Draw1 : public BaseDraw
{
public:
	void Draw() {std::cout << "Drawing1:\n /\\ \n//\\\\" << std::endl;}
};

class Draw2 : public BaseDraw
{
public:
	void Draw() {std::cout << "Drawing2:\n /\\ \n/**\\" << std::endl;}
};

class Draw3 : public BaseDraw
{
public:
	void Draw() {std::cout << "Drawing3:\n /\\ \n/++\\" << std::endl;}
};

int main(void)
{
	BaseDraw *draws[3];
	
	draws[0] = new Draw1();
	draws[1] = new Draw2();
	draws[2] = new Draw3();
	
	for(int i = 0; i < 3; i++)
		draws[i]->Draw();
	
	return 0;
}