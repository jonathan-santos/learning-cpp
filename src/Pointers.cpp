#include <iostream>

void SimplePointer()
{
    void* simplePtr = nullptr; // Points to a nowhere
    std::cout << simplePtr << std::endl << std::endl; // will print 0, but it's real value is 0x0, which is a hexadecimal value meaning to nowhere
}

void PointToData()
{
    int a = 5;
    int* ptr = &a; // & (address of operator) operator returns the memory address to a variable
    std::cout << "Variable a with value " << a << " is located at: " << ptr << std::endl << std::endl; // 0x7fffe4ccb16c, the memory address to the variable a. Everytime it is different
}

void ChangePointerData()
{
    int a = 0;
    int* ptr = &a;

    std::cout << "a[before]: " << a << std::endl; // 0

    // ptr = 5; Will not affect variable a, because it is a pointer. Doing this will make the pointer point to memory address 5, which likely does not exist
    *ptr = 5; // *var (dereference operator) Will get the data the pointer points to. We can read the value or change it
    
    std::cout << "a[after]: " << a << std::endl << std::endl; // 5
}

void PointerToPointer()
{
    int a = 5;
    int* ptr = &a;
    int** ptrToPtr =  &ptr;

    std::cout << "a: " << a << ", ptr to a: " << ptr << ", ptr to ptr to a: " << ptrToPtr << std::endl << std::endl;
}

void ExecutePointers()
{
    SimplePointer();
    PointToData();
    ChangePointerData();
    PointerToPointer();
}
