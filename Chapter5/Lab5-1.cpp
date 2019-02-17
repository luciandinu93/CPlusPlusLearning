/* Represent a preson in form of classes */

#include <iostream>
#include <string>

class Person
{
    public:
        std::string name;
        int age;
        void sayHi(void);
};

void Person::sayHi(void)
{
    std::cout << "HI, my name is " << this->name << " and i am " << this->age << " years old!" << std::endl;
}

void print(Person *person)
{
    std::cout << person->name << " is " << person->age << " years old." << std::endl;
}

int main(void)
{
    Person person;
    person.name = "Harry";
    person.age = 23;

    std::cout << "Meet " << person.name << std::endl;
    print(&person);

    person.sayHi();

    return 0;
}
