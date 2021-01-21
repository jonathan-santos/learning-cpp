#include <iostream>

void SomeFunction()
{
    std::cout << "Do something" << std::endl;
}

int Add(int a, int b)
{
    return a + b;
}

void ExecuteFunctions()
{
    SomeFunction();
    std::cout << "The result of 1 + 1 is: " << Add(1, 1) << std::endl;
}
