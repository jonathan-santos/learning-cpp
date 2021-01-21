#include <iostream>

template<typename T>
class Vector
{
public:
    Vector()
    {
        ReAlloc(2);
    }

    ~Vector()
    {
        delete[] m_Data;
    }

    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T&& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_Data[m_Size] = std::move(value);
        m_Size++;
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_Data[m_Size] = T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }

    void PopBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    size_t Size() const { return m_Size; }
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

    void ReAlloc(size_t newCapacity)
    {
        T* newBlock = new T[newCapacity];

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++)
            newBlock[i] = std::move(m_Data[i]);

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
};

struct Vector3Vec
{
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vector3Vec() { }
    Vector3Vec(float scalar) : x(scalar), y(scalar), z(scalar) { }
    Vector3Vec(float x, float y, float z) : x(x), y(y), z(z) { }

    Vector3Vec(const Vector3Vec& other) : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied\n";
    }

    Vector3Vec operator=(const Vector3Vec& other)
    {
        std::cout << "Copied\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3Vec operator=(const Vector3Vec&& other)
    {
        std::cout << "Moved\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3Vec(const Vector3Vec&& other) : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Moved\n";
    }

    ~Vector3Vec()
    {
        std::cout << "Destroyed\n";
    }
};

std::ostream& operator<<(std::ostream& stream, Vector3Vec& vec)
{
    stream << vec.x << ", " << vec.y << ", " << vec.z;
    return stream;
}

template<typename T>
void PrintVector(T vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i] << std::endl;
    std::cout << "---------------" << std::endl;
}

void ExecuteCustomDynamicArray()
{
    Vector<std::string> stringCollection;
    stringCollection.PushBack("Jhow");
    stringCollection.PushBack("C++");
    stringCollection.PushBack("Vector");
    PrintVector(stringCollection);

    Vector<Vector3Vec> vector3Collection;
    // vector3Collection.PushBack(Vector3Vec(1.0f));
    // vector3Collection.PushBack(Vector3Vec(1.0f, 2.0f, 3.0f));
    // vector3Collection.PushBack(Vector3Vec());
    vector3Collection.EmplaceBack(Vector3Vec(1.0f));
    vector3Collection.EmplaceBack(Vector3Vec(1.0f, 2.0f, 3.0f));
    vector3Collection.EmplaceBack(Vector3Vec());
    PrintVector(vector3Collection);
}
