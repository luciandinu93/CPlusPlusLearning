#include <iostream>

class Stack
{
    private:
        int stackstore[100];
        int SP;
    public:
        Stack(void) { SP = 0; }
        void push(int value);
        int pop(void)
        {
            return stackstore[--SP];
        }
};

void Stack::push(int value)
{
    stackstore[SP++] = value;
}

class AddingStack : Stack
{
    private:
        int sum;
    public:
        AddingStack(void);
        void push(int value);
        int pop(void);
        int getSum(void);
};

AddingStack::AddingStack(void) : Stack()
{
    sum = 0;
}

void AddingStack::push(int value)
{
    sum += value;
    Stack::push(value);
}

int AddingStack::pop(void)
{
    int val = Stack::pop();
    sum -= val;
    return val;
}

int AddingStack::getSum(void)
{
    return sum;
}

int main(void)
{
    AddingStack super_stack;

    for(int i = 1; i < 10; i++)
    {
        super_stack.push(i);
    }
    std::cout << super_stack.getSum() << std::endl;

    for(int i = 1; i < 10; i++)
    {
        super_stack.pop();
    }
    std::cout << super_stack.getSum() << std::endl;

    return 0;
}
