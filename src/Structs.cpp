#include <iostream>

// Basically structs are the same as classes, but instead of members being private by default as classes, they are public

struct Vector2
{
    float x, y;

    Vector2(float x, float y) : x(x), y(y) { }

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

void ExecuteStructs()
{
    Vector2 v(1, 1);
    v.Print();
}
