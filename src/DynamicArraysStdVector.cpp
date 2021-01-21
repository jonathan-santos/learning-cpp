#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) { }

    Vertex(const Vertex& other)
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Vertex copied" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& v)
{
    stream << v.x << ", " << v.y << ", " << v.z;
    return stream;
}

void PrintVertices(const std::vector<Vertex>& vertices)
{
    // for (int i = 0; i < vertices.size(); i++) // Old way of looping through items in a vector
    //     std::cout << vertices[i] << std::endl;

    for (const Vertex& v : vertices) // Dont let it as only Vertex in type, otherwise needless copying will happen
        std::cout << v << std::endl;
}

void AddItems(std::vector<Vertex>& vertices)
{
    for (int i = 0; i < 5; i++)
    {
        //vertices.push_back({ float(i), float(i), float(i) }); // It works, but it will cause an copy of the vertex object before being added to vertices array
        vertices.emplace_back(float(i), float(i), float(i)); // Instead of passing an object to the function, you pass the parameters to construct the object, then the dynamic array will take care of constructing the object already at it's memory location, preventing copying
    }

    std::cout << "vertices - 5 items added. Size: " << vertices.size() << std::endl;

    vertices.emplace_back(10.0f, 10.0f, 10.0f); // When this is executed, there will be 5 vertex copies happening, because we reserved 5 spaces when we created the array vertices. So when we try to add one more object, it will create a new array with sufficient space (6 instead of 5), copy the old items (that's why there were 5 copies, because there were 5 items) into the new array and delete the old one. Very inefficient. The only way to prevent this is to reserve more memory to the array BEFORE you start adding items to it

    std::cout << "vertices - 1 more items added. Size: " << vertices.size() << std::endl;
}

void DeleteItems(std::vector<Vertex>& vertices)
{
    vertices.pop_back();

    // Erase takes an iterator
    vertices.erase(vertices.begin() + 1); // Deletes vertices[1]

    std::cout << "vertices - 2 items removed. Size: " << vertices.size() << std::endl;
}

void ExecuteDynamicArraysStdVector()
{
    std::vector<Vertex> vertices;
    vertices.reserve(5); // This will "reserve" 5 memory blocks for vertices objects, preventing memory copy when it is resized. Doesn't work when it already has items in it
    std::cout << "Dynamic array vertices created. Size: " << vertices.size() << std::endl;

    AddItems(vertices);
    std::cout << std::endl;
    PrintVertices(vertices);
    std::cout << std::endl;
    DeleteItems(vertices);
    std::cout << std::endl;
    PrintVertices(vertices);
}
