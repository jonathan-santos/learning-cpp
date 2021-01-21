#include <iostream>
#include <cstring>

class StringMove
{
public:
    StringMove() = default;
    StringMove(const char* string)
    {
        printf("Created\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    StringMove(const StringMove& other) // Copy
    {
        printf("Copied\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    StringMove(StringMove&& other) noexcept // Move (noexpect means that there will be no exceptions in this method)
    {
        printf("Moved\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    StringMove& operator=(StringMove&& other) noexcept
    {
        printf("Assigned\n");

        if (this != &other)
        {
            delete[] m_Data;
            
            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        return *this;
    }
    
    ~StringMove()
    {
        printf("Destroyed\n");
        delete[] m_Data;
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
            printf("%c", m_Data[i]);
        printf("\n");
    }
private:
    char* m_Data;
    uint32_t m_Size;
};

class EntityMove
{
public:
    EntityMove(const StringMove& name) : m_Name(name) { }
    EntityMove(StringMove&& name) : m_Name(std::move(name)) { }

    void PrintName()
    {
        m_Name.Print();
    }
private:
    StringMove m_Name;
};

void ExecuteMoveSemantics()
{
    EntityMove e("Jhow");
    e.PrintName();

    std::cout << std::endl;

    StringMove string = "Hello";
    //String dest = string; // Copy
    // StringMove dest = (StringMove&&) string; // Move
    StringMove dest = std::move(string); // Move
    string.Print(); // "" because it was moved, so the variable that originally holded it now has nothing
    dest.Print(); // Hello
}