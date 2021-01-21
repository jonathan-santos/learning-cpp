#include <iostream>
#include <string>

class Entity
{
private:
    int m_Value = 0;
public:
    std::string Name;

    Entity()
    {
        m_Value = 1;
        Name = "Unkown";
    }

    Entity(int value, std::string name)
        : m_Value(value), Name(name) { } // Must be declared in order

    int GetValue() const //Const after method declaration means that it will not change values of the object. Necessary for method to be usable by const objects of the type
    {
        return m_Value;
    }

    void Print()
    {
        std::cout << Name << ": " << m_Value << std::endl;
    }
};

void PrintEntity(const Entity& e) // Without using references it duplicates the object in memory
{
    std::cout << e.Name << ": " << e.GetValue() << std::endl;
}

void ExecuteClasses()
{
    Entity e; // No constructor
    e.Print();

    Entity e2(5, "A name"); // To use a constructor
    PrintEntity(e2);

    Entity e3 = Entity(10, "Other name"); // Another way to build the object, not necessary
    e3.Print();

    PrintEntity(Entity(15, "One other name")); // Create a object without saving it to a variable
}
