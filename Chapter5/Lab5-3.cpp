/* Obtain derived data from an object*/

#include <iostream>

class AdHocSquare 
{
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area(void);
    void print(void);
private:
    double side;
};

AdHocSquare::AdHocSquare(double side)
{
    this->side = side;
}

void AdHocSquare::set_side(double side)
{
    if(side < 0)
    {
        std::cout << "The side can not be a negative number, your entry is: " << side << std::endl;
    }
    else
    {
        this->side = side;
    }
}

double AdHocSquare::get_area(void)
{
    return this->side * this->side;
}

void AdHocSquare::print(void)
{
    std::cout << "Square: side=" << this->side << " area=" << this->get_area() << std::endl;
}

class LazySquare
{
public:
    LazySquare(double side);
    void set_side(double side);
    double get_area(void);
    void print(void);
private:
    double side;
    double area;
    bool side_changed;
};

LazySquare::LazySquare(double side)
{
    this->side = side;
    this->area = side * side;
    this->side_changed = false;
}

void LazySquare::set_side(double side)
{
    if(side < 0)
    {
        std::cout << "The side can not be a negative number, your entry is: " << side << std::endl;
    }
    else
    {
        this->side = side;
        this->side_changed = true;
    }
}

double LazySquare::get_area(void)
{
    if(this->side_changed)
        return this->side*this->side;
    else
        return this->area;
}

void LazySquare::print(void)
{
    std::cout << "Square: side=" << this->side << " area=" << this->get_area() << std::endl;
}

int main(void)
{
    AdHocSquare as(4);
    LazySquare ls(4);

    as.print();
    ls.print();

    as.set_side(2.0);
    ls.set_side(2.0);

    as.print();
    ls.print();

    as.set_side(-33);
    ls.set_side(-33);

    as.print();
    ls.print();

    return 0;
}
