#include <iostream>

 // Name doesn't need to start with I
class IEntity
{
public:
    virtual void Print() = 0; // Now if the Child class doesn't override the method, the code won't compile
};

class IEntityChild : public IEntity
{
public:
    void Print()
    {
        std::cout << "Hello from Interface inherited child" << std::endl;
    }
};

void ExecuteEntityPrint(IEntity& e)
{
    e.Print();
}

void ExecuteInterface()
{
    IEntityChild e;
    ExecuteEntityPrint(e);
}
