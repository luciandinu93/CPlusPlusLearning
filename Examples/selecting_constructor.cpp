#include <iostream>

class Class
{
    public:
        Class(void)
        {
            std::cout << "Object constructed (#1)" << std::endl;
        }

        Class(int v)
        {
            value = v;
            std::cout << "Object constructed (#2)" << std::endl;
        }

        ~Class(void)
        {
            std::cout << "Object destructed! val = " << value << std::endl;
        }

        void IncAndPrint(void)
        {
            std::cout << "value= " << ++value << std::endl;
        }

        int value;
};

int main(void)
{
    Class *ptr1, *ptr2;

    ptr1 = new Class;
    ptr2 = new Class(2);

    ptr1->value = 1;
    ptr1->IncAndPrint();
    ptr2->IncAndPrint();
    delete ptr2;

    return 0;
}
