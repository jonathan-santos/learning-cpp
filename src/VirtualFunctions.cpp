#include <iostream>

class EntityVirtual
{
public:
    virtual void Print() // Without the virtual keyword, even with defining a Print method in Child, the parent Print is executed
    {
        std::cout << "Hello from Parent Entity" << std::endl;
    }
};

class EntityVirtualChild : public EntityVirtual
{
public:
    const char* Name;

    EntityVirtualChild(const char* name) : Name(name) { }
    
    void Print() override // The override keyword is optional, but very recommended, because it will give compiler errors for wrongly typed method names, or try of overriding a not virtual method
    {
        std::cout << "Hello form Child Entity with name " << Name << std::endl;
    }
};

void PrintEntity(EntityVirtual& e)
{
    e.Print();
}

void ExecuteVirtualFunctions()
{
    EntityVirtual p;
    EntityVirtualChild c("Child");
    PrintEntity(p);
    PrintEntity(c);
}
