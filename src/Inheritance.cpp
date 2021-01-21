#include <iostream>
#include <string>

using String = std::string;

class ParentEntity
{
private:
    bool parentExclusiveMember = true;
public:
    String Name;

    ParentEntity() : Name("Unkown") { }

    ParentEntity(String name) : Name(name) { }
};

class ChildEntity : public ParentEntity
{
private:
    int m_Value;
public:
    ChildEntity() : m_Value(0) { }
    ChildEntity(String name, int value) : m_Value(value) { Name = name; }

    int GetValue() const
    {
        return m_Value;
    }
};

void ExecurteInheritance()
{
    ParentEntity p1;
    std::cout << p1.Name << std::endl;

    ParentEntity p2("Parent");
    std::cout << p2.Name << std::endl;

    ChildEntity c1;
    std::cout << c1.Name << ", " << c1.GetValue() << std::endl;

    ChildEntity c2("Child", 1);
    std::cout << c2.Name << ", " << c2.GetValue() << std::endl;
}
