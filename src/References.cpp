#include <iostream>

void CreatingReferences()
{
    int a = 5;
    int& b = a; // To create a reference, in the type add operator & in the end
    b++;
    std::cout << "a: " << a << std::endl << std::endl;
}

void IncreaseNumberWithValue(int number)
{
    number += 1;
}

void FailedChangeWithValue()
{
    std::cout << "FailedChangeWithValue: " << std::endl;
    int a = 0;
    std::cout << "a[before]: " << a << std::endl; // 0
    IncreaseNumberWithValue(a);
    std::cout << "a[after]: " << a << std::endl << std::endl; // 0
}

void IncreaseNumberWithPointer(int* number)
{
    (*number)++;
}

void ChangeValueWithPointer()
{
    std::cout << "ChangeValueWithPointer: " << std::endl;
    int a = 0;
    std::cout << "a[before]: " << a << std::endl; // 0
    IncreaseNumberWithPointer(&a);
    std::cout << "a[after]: " << a << std::endl << std::endl; // 0
}

void IncreaseNumberWithReference(int& number)
{
    number++;
}

void ChangeValueWithReference()
{
    std::cout << "ChangeValueWithReference: " << std::endl;
    int a = 0;
    std::cout << "a[before]: " << a << std::endl; // 0
    IncreaseNumberWithReference(a);
    std::cout << "a[after]: " << a << std::endl << std::endl; // 1
}

void ExecuteReferences()
{
    CreatingReferences();
    FailedChangeWithValue();
    ChangeValueWithPointer();
    ChangeValueWithReference();
}
