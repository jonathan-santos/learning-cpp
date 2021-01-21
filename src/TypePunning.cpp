#include <iostream>

struct EntityTypePunning
{
    int x, y;

    EntityTypePunning() : x(10), y(20) { }
};

void PunningValues()
{
    int a = 50;
    // double b = (double)a; // Valid. But unnecessary, because int can be converted to double implicitly
    // double b = *(double*)&a; // Valid. This is what happens in the background, we take the int pointer to a, convert it into a double pointer and then derefence it
    double b = a; // Valid. But will copy the value
    std::cout << "[double] b: " << b << std::endl;
}

void PunningStructsAndClasses()
{
    EntityTypePunning e;
    int* positionsArray = (int*)&e;
    std::cout << "positionsArray[0]: " << positionsArray[0] << std::endl;
    std::cout << "positionsArray[1]: " << positionsArray[1] << std::endl;

    int y = *(int*)((char*)&e + 4); // Were converting the int pointer of e to a char pointer, moving 4 bytes forward, converting this address to a int pointer and then dereferencing it
    std::cout << "y of e: " << y << std::endl;
}

void ExecuteTypePunning()
{
    PunningValues();
    PunningStructsAndClasses();
}
