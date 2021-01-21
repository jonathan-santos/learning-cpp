#include <iostream>

template<typename T, size_t S> // size_t is just a int strictly used for defining sizes in the C++ STL, so it's better to use it here
class Array
{
public:
    constexpr size_t Size() const { return S; } // constexpr signals that this function can be run at compile time

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }

    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }
private:
    T m_Data[S];
};

void ExecuteCustomArray()
{
    Array<int, 5> collection;
    std::cout << "collection size: " << collection.Size() << std::endl; // 5

    for (int i = 0; i < collection.Size(); i++)
    {
        collection[i] = i;
        std::cout << i << ","; // 0, 1, 2, 3, 4, 
    }
}
