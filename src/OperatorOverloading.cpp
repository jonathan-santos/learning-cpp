#include <iostream>

// All operators are methods, you just need to add a overload to them

struct VectorOperator
{
    float x, y;

    VectorOperator(float x, float y) : x(x), y(y) { }

    VectorOperator operator+(VectorOperator& other)
    {
        return VectorOperator(x + other.x, y + other.y);
    }

    VectorOperator operator*(VectorOperator& other)
    {
        return VectorOperator(x * other.x, y * other.y);
    }

    bool operator==(VectorOperator& other)
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(VectorOperator& other)
    {
        return !((*this) == other);
    }
};

std::ostream& operator<<(std::ostream& stream, VectorOperator v)
{
    stream << v.x << ", " << v.y;
    return stream;
}

void ExecuteOperatorOverloading()
{
    VectorOperator v1(5.0f, 5.0f);
    VectorOperator v2(10.0f, 10.0f);

    std::cout << "Vector1: " << v1.x << ", " << v1.y << std::endl; // Normally
    std::cout << "Vector2: " << v2 << std::endl; // With operator overloading

    std::cout << "Vector 1 + Vector2: " << v1 + v2 << std::endl;
    std::cout << "Vector 1 * Vector2: " << v1 * v2 << std::endl;
    std::cout << "Vector 1 == Vector2: " << (v1 != v2) << std::endl;
}
    
