#include <iostream>

enum Values1
{
    a, b, c // 0, 1, 2
};

enum Values2
{
    D = 1, E, F // 1, 2, 3
};

class EntityWithEnums
{
public:
    enum Values
    {
        A = 10, B = 20, C = 30
    };

    Values Value;

    EntityWithEnums() : Value(A) { }

    EntityWithEnums(Values v) : Value(v) { }
};

void ExecuteEnums()
{
    Values1 v1 = a;
    std::cout << v1 << std::endl; // 0

    Values2 v2 = Values2::E;
    std::cout << v2 << std::endl; // 2

    EntityWithEnums e1;
    std::cout << e1.Value << std::endl; // 10

    EntityWithEnums e2(EntityWithEnums::C);
    std::cout << e2.Value << std::endl; // 30

    std::cout << "Is the Value of e2 C? " << (e2.Value == EntityWithEnums::C) << std::endl;
}
