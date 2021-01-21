#include <iostream>

// Static inside classes (and structs) basically create instances of variables and methods that are independent of instances of the class

class EntityStatic
{
public:
    const char* Name;
    static int Value;

    EntityStatic(const char* name) : Name(name) { }

    void Print()
    {
        //Value = 10; // Valid. Non static members do have access to static members of the class/struct
        //StaticPrint(); // Valid. Same with methods
        std::cout << Name << ": " << Value << std::endl;
    }

    static void StaticPrint()
    {
        //Name = "Something"; // Invalid. Static members do not have access to non-static members of the class/struct
        //Print(); // Invalid. Same with methods
        std::cout << "Static Print" << std::endl;
    }
};

int EntityStatic::Value = 1; // Even if the class defines the static property Value, you need to define it outside the class too, to be used outside of the class, like defining the initial value
// For example, without this definition, even if the property Value is being called inside the EntityStatic class, it results in an run time error saying that Value is not defined
// Methods don't need this "redefinition" for usage inside or outside class/struct

void ExecuteStaticInside()
{
    EntityStatic e1("Jhow");
    EntityStatic e2("John");

    std::cout << "EntityStatic::Value: " << EntityStatic::Value << std::endl; // 1
    e1.Print(); // Jhow: 1
    e2.Print(); // John: 1
    std::cout << std::endl;

    EntityStatic::Value = 5;

    std::cout << "EntityStatic::Value: " << EntityStatic::Value << std::endl; // 5
    e1.Print(); // Jhow: 5
    e2.Print(); // John: 5
    std::cout << std::endl;

    EntityStatic::StaticPrint();
}
