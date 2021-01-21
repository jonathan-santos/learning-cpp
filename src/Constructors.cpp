#include <iostream>

class EntityWithConstructor
{
public:
    EntityWithConstructor()
    {
        std::cout << "Entity constructed" << std::endl;
    }
};

class EntityWithoutConstructor
{
public:
    EntityWithoutConstructor() = delete;

    static void Print()
    {
        std::cout << "Basically without a constructor the class can only have static methods and properties";
    }
};

void ExecuteConstructors()
{
    EntityWithConstructor e;
    // EntityWithoutConstructor e2; Will generate an error
    EntityWithoutConstructor::Print();
}
