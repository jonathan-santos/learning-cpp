#include <iostream>

// The arrow operator is just syntax sugar to simplify the use of pointers in your code

class EntityArrow
{
private:
    int m_Value = 5;
public:
    const char* Name = "Unknown";

    int GetValue() const
    {
        return m_Value;
    }
};

void ExecuteArrow()
{
    EntityArrow* e = new EntityArrow();

    (*e).Name = "Something"; // Normal way of accessing a property from a pointer, you need to "destructure" the pointer, then you get access to the values of the type
    e->Name = "Other something"; // Arrow operator

    std::cout << e->Name << ": " << e->GetValue() << std::endl; // Other something: 5

    delete e;
}
