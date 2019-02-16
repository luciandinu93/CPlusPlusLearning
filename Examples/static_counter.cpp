#include <iostream>

class Class
{
    public:
        static int Counter;
        Class(void) {++Counter;}
        ~Class(void) {--Counter; if(Counter == 0) std::cout << "Bye Bye!" << std::endl;}
        void HowMany(void) {std::cout << Counter << " instances" << std::endl;}
};

int Class::Counter = 0;

int main(void)
{
    Class a;
    Class b;
    std::cout << Class::Counter << " instances so far" << std::endl;
    Class c;
    Class d;
    d.HowMany();

    return 0;
}
