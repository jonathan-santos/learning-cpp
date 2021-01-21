#include <iostream>

// Implicit construction is the ability to construct a object by assigning a value and calling the appropriate constructor that way
// Explicit is a keyword that can be added to constructors of a class to disable implicit construction

class EntityImplicit
{
public:
    int Value;
    EntityImplicit(int value) : Value(value) { }
};


class EntityExplicit
{
public:
    int Value;
    explicit EntityExplicit(int value) : Value(value) { }
};

void Print(const EntityImplicit& e)
{
    std::cout << "Print implicity: " << e.Value << std::endl;
}

void ExecuteImplicitAndExplicit()
{
    //EntityImplicit e1(10); // Normal way of constructing object
    EntityImplicit e1 = 10; // Works the same as above
    std::cout << "Implicit: " << e1.Value << std::endl;

    Print(10); // Implicit construction works in functions too

    // EntityExplicit e2 = 20; // Invalid. Thanks to the explicit keyword in the constructor, implicit construction of object (with this constructor at least) is disabled.
    EntityExplicit e2(20); // Valid
    std::cout << "Explicit: " << e2.Value << std::endl;
}
