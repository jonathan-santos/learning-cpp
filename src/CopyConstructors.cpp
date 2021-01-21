#include <iostream>
#include <cstring>

void ValuesDoCopy()
{
    int a = 1;
    int b = a;
    b++;
    std::cout << "Value do not copy[a]: " << a << std::endl; // 1
    std::cout << "Value do not copy[b]: " << b << std::endl; // 2
}

struct VectorCopy
{
    float x, y;
};

void ClassesAndStructsDoCopy()
{
    VectorCopy a = { 1, 3 };
    VectorCopy b = a;
    b.x = 10;
    b.y = 30;
    std::cout << "Classes and structs do not copy[Vector a]: (x): " << a.x << ", (y): " << a.y << std::endl;
    std::cout << "Classes and structs do not copy[Vector b]: (x): " << b.x << ", (y): " << b.y << std::endl;
}

void PointersCopyThePointerNotTheValue()
{
    int* a = new int(1);
    int* b = a;
    (*b)++;
    std::cout << "Pointers copy the pointer, not the value[a]: " << *a << std::endl; // 2
    std::cout << "Pointers copy the pointer, not the value[b]: " << *b << std::endl; // 2
    delete a;

    VectorCopy* c = new VectorCopy();
    (*c).x = 1;
    (*c).y = 3;

    VectorCopy* d = c;
    (*d).x = 10;
    (*d).y = 30;

    std::cout << "Pointers copy the pointer, not the value[Vector c]: (x): " << c->x << ", (y): " << c->y << std::endl;
    std::cout << "Pointers copy the pointer, not the value[Vector d]: (x): " << d->x << ", (y): " << d->y << std::endl;
    delete c;
}

class BasicString
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    BasicString(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    ~BasicString()
    {
        delete[] m_Buffer;
    }

    //BasicString(const BasicString& other); // Copy constructor
    //BasicString(const BasicString& other) = delete; // Disable Copy constructor
    BasicString(const BasicString& other) // Deep copy. As in it guarantees that when being copied, BasicString will not copy m_Buffer as a pointer, but it will copy the value inside m_Buffer from the copied object to the new, while them both having different memory locations
        : m_Size(other.m_Size)
    {
        std::cout << "Copied BasicString" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const BasicString& string);
};

std::ostream& operator<<(std::ostream& stream, const BasicString& string)
{
    stream << string.m_Buffer;
    return stream;
}

void CopyOperator()
{
    BasicString string = "Jhow";
    BasicString secondString = string;
    secondString[0] = 'j';
    std::cout << "string: " << string << std::endl;
    std::cout << "secondString: " << secondString << std::endl;
}

void PrintByValue(BasicString e)
{
    std::cout << "By Value: " << e << std::endl;
}

void PrintByPointer(BasicString* e)
{
    std::cout << "By pointer: " << *e << std::endl;
}

void PrintByReference(BasicString& e)
{
    std::cout << "By reference: " << e << std::endl;
}

// When passing a object as a parameter to a function, you gotta be careful as how it is defined in the function. In the example bellow, when we pass the variable string to function PrintByValue, the variable string is actually being copied in memory to the function. The other two don't have the same behavior, saving memory and processing
void FunctionCopy()
{
    BasicString string = "Jhow";
    PrintByValue(string); // Will appear "Copied BasicString" in console, because the Copy constructor was called
    PrintByPointer(&string); // No duplication
    PrintByReference(string); // No duplication
}

void ExecuteCopyConstructors()
{
    ValuesDoCopy();
    std::cout << std::endl;
    ClassesAndStructsDoCopy();
    std::cout << std::endl;
    PointersCopyThePointerNotTheValue();
    std::cout << std::endl;
    CopyOperator();
    std::cout << std::endl;
    FunctionCopy();
}
