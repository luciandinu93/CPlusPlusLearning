/* ShopItemOrder - CLASS - 
 * TO DO:
 * Class name: ShopItemOrder
 * Item shall be stoderd the following information : 
 * 1. item name;
 * 2. item unit price;
 * 3. number of items ordered;
 * There will be access methods allowing to:
 * 1. get and set all informations
 * 2. get the total price for the order
 * 3. print the order in user-friendly way
 * */

#include <iostream>
#include <string>

class ShopItemOrder
{
public:
    ShopItemOrder(std::string name, double price, int numberOfItems);
    void set_name(std::string name);
    void set_price(double price);
    void set_numberOfItems(int numberOfItems);
    std::string get_name(void);
    double get_price(void);
    int get_numberOfItems(void);
    double get_total(void);
    void print_order(void);
private:
    std::string name;
    double price;
    int numberOfItems;
};

ShopItemOrder::ShopItemOrder(std::string name, double price, int numberOfItems)
{
    this->name = name;
    this->price = price;
    this->numberOfItems = numberOfItems;
}

void ShopItemOrder::set_name(std::string name)
{
    this->name = name;
}

void ShopItemOrder::set_price(double price)
{
    this->price = price;
}

void ShopItemOrder::set_numberOfItems(int numberOfItems)
{
    this->numberOfItems = numberOfItems;
}

std::string ShopItemOrder::get_name(void)
{
    return this->name;
}

double ShopItemOrder::get_price(void)
{
    return this->price;
}

int ShopItemOrder::get_numberOfItems(void)
{
    return this->numberOfItems;
}

double ShopItemOrder::get_total(void)
{
    return (this->get_price() * this->get_numberOfItems());
}

void ShopItemOrder::print_order(void)
{
    std::cout << "Your order is: " << std::endl;
    std::cout << this->get_numberOfItems() << " x " << this->get_name() << " for " << this->get_price() <<
        "$ each ." << std::endl;
    std::cout << "\tTotal of your order is " << this->get_total() << "$" << std::endl;
}

int main(void)
{
    ShopItemOrder sio("Calculatoare", 2509.99, 15);

    sio.print_order();

    return 0;
}
