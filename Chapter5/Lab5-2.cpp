/* Setters and getters
 * TO DO:
 * 1. Hide the area and side memebers using the keyword private
 * 2. Add public method set_side to the square class 
 * 3. set_side should also ignore the change if the argument is less than 0
 * 4. Create a public method of printing Square
 * */

#include <iostream>

class Square
{
public:
    Square(double side);
    void set_side(int side);
    void print(void);
private:
    double side;
    double area;
};

void Square::set_side(int side)
{
    if(side < 0)
    {
        std::cout << "Can not set side to = " << side << ", the modification will be ignored." << std::endl;
    }
    else
    {
        this->side = side;
        this->area = side * side;
    }
}

Square::Square(double side)
{
    this->side = side;
    this->area = side * side;
}

void Square::print(void)
{
    std::cout << "Square: side=" << this->side << " area=" << this->area << std::endl;
}

int main(void)
{
    Square s(4);

    s.print();

    s.set_side(2.0);
    s.print();

    s.set_side(-33);
    s.print();

    return 0;
}
