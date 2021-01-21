#include <iostream>

// Const doesn't really affect the final code, it's just a mechanism to enforce some rules on our code to the compiler and affect visibility of some of class members and variables

class EntityConst
{
private:
    int m_X, m_Y;
    int* m_Z;
    mutable int m_A; // mutable properties can be changed inside const methods...
public:
    int GetX()
    {
        return m_X;
    }

    int GetY() const // const after a method name means that the method WILL NOT modify any members of the class. Necessary for use of constant EntityConst objects which want to use this method
    {
        // m_Y = 2; Will generate an error
        m_A = 5; // Can be changed because it is marked mutable
        return m_Y;
    }

    const int* const GetZ() const // ..., a method which will not change anything in the class which returns a constant pointer to a constant value...
    {
        return m_Z;
    }
};

void PrintEntityConst(EntityConst& e) // Will work perfectly
{
    std::cout << e.GetX() << std::endl;
    std::cout << e.GetY() << std::endl;
}

void PrintEntityConst(const EntityConst& e)
{
    // std::cout << e.GetX() << std::endl; Will generate error, because the EntityConst e is constant, and the method GetX is not guaranteed to not change the value inside
    std::cout << e.GetY() << std::endl; // Will work perfectly
}

void ExecuteConst()
{
    const int a  = 1; // const in a non pointer variable will "LOCK" it's value to the initial one given to it
    // a = 10; Will generate an error

    const int* b = new int(2); // const before a pointer (*) symbol will result in a constant value to the value the pointer "points", 
    b = new int(20); // Valid
    // *b = 20; Will generate an error

    int* const c = new int(3); // const after a pointer (*) symbol and before the variable name will make a constant POINTER, you can change the value the pointer is pointing to, but you cannot change what the pointer is pointing
    *c = 30; // Valid
    // *c = new int(30); Will generate an error

    const int* const d = new int(4); // You can combine the cons options, making the pointer itself and the value it is pointing to, constant
    // *d = 40; Will generate an error
    // *d = new int(30); Will generate an error

    EntityConst entity;
    // int* z = entity.GetZ(); Will generate an error, because the variable needs to be constant to get the value
    const int* z = entity.GetZ();
    // *z = 10; Will generate an error, because even tough the variable z isn't "value constant", the memory location it points to is m_Z;
}
