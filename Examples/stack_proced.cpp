#include <iostream>

int stack[100];
int SP = 0;

void push(int value)
{
    stack[SP++] = value;
}

int pop(void)
{
    return stack[--SP];
}

int main(void)
{
    push(3);
    push(2);
    push(1);
    std::cout << pop() << std::endl;
    std::cout << pop() << std::endl;
    std::cout << pop() << std::endl;

    return 0;
}
