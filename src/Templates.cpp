#include <iostream>
#include <string>

// void Print(int value)
// {
//     std::cout << value << std::endl;
// }

// void Print(std::string value)
// {
//     std::cout << value << std::endl;
// }

// Works the same as the above two functions
//template<class T> // Works the same, but I think typename makes more sense
template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

void UseTemplateFunction()
{
    Print(5);
    //Print<int>(5); // Also valid. But in this case optional as it is having implicit type declaration
    Print("Hello there");
    Print(5.5f);
}

template<typename T, int size>
class Array
{
private:
    T m_Array[size];
public:
    int GetSize()
    {
        return size;
    }
};

void UseTemplateClass()
{
    Array<int, 5> array;
    std::cout << "array size: " << array.GetSize() << std::endl;
}

void ExecuteTemplates()
{
    UseTemplateFunction();
    UseTemplateClass();
}
