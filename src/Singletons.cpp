#include <iostream>

// Old way of doing Singletons, might see it around. Has the same effect as the new bellow, but with a bit more code
// class SingletonOld
// {
// private:
//     static SingletonOld* s_Instance;
// public:
//     static SingletonOld& Get()
//     {
//         return *s_Instance;
//     }
// };

// SingletonOld* SingletonOld::s_Instance = nullptr;

class Singleton
{
private:
    float m_X, m_Y;
public:
    Singleton()
    {
        m_X = 0.0f;
        m_Y = 0.0f;    
    }

    static Singleton& Get()
    {
        static Singleton instance;
        return instance;
    }

    void SetX(float x)
    {
        m_X = x;
    }

    void SetY(float y)
    {
        m_Y = y;
    }

    void Print()
    {
        std::cout << "x: " << m_X << ", y: " << m_Y << std::endl;
    }
};

void ExecuteSingletons()
{
    {
        Singleton::Get().Print();
        Singleton::Get().SetX(10.0f);
        Singleton::Get().SetY(20.0f);
        Singleton::Get().Print();
    }

    {
        Singleton::Get().Print();
    }
}
