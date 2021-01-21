#include <iostream>

void AnonymousUnion()
{
    struct Union
    {
        union
        {
            float a;
            int b;
        };
    };

    Union u;
    u.a = 2.0f;
    std::cout << "u.a: " << u.a << std::endl;
    std::cout << "u.b: " << u.b << std::endl;
}

struct Vector2Union
{
    float x, y;
};

struct Vector4Union
{
    union
    {
        struct
        {
            float x, y, z, w;
        };

        struct
        {
            Vector2Union a, b;
        };
        
    };
};

void PrintVector2Union(const Vector2Union& vec)
{
    std::cout << vec.x << ", " << vec.y << std::endl;
}

void Something()
{
    Vector4Union vector = { 1.0f, 2.0f, 3.0f, 4.0f };
    PrintVector2Union(vector.a); // 1.0, 2.0
    PrintVector2Union(vector.b); // 3.0, 4.0
}

void ExecuteUnions()
{
    AnonymousUnion();
    Something();
}
