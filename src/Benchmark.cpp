#include <iostream>
#include <chrono>
#include <array>
#include <memory>

class Benchmark
{
private:
    const char* m_Name;
    std::chrono::high_resolution_clock::time_point m_Start, m_End;
    long long start, end;
public:
    Benchmark(const char* name) : m_Name(name)
    {
        m_Start = std::chrono::high_resolution_clock::now();
    }

    ~Benchmark()
    {
        m_End = std::chrono::high_resolution_clock::now();

        start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_Start).time_since_epoch().count();
        end = std::chrono::time_point_cast<std::chrono::milliseconds>(m_End).time_since_epoch().count();

        std::cout << "[" << m_Name << "]: " << (end - start) << "ms\n";
    }
};

void BenchmarkSimpleLoop()
{
    int value = 0;
    {
        Benchmark b("Simple loop");
        for (int i = 0; i < 10000000; i++)
            value += 2;
    }
}

void BenchmarkSharedPointer()
{
    struct Vector2
    {
        float x, y;
    };

    {
        std::array<std::shared_ptr<Vector2>, 1000> shared_ptrs;
        Benchmark b("Shared pointers with make_shared");
        for (int i = 0; i < 1000; i++)
            shared_ptrs[i] = std::make_shared<Vector2>();
    }

    {
        std::array<std::shared_ptr<Vector2>, 1000> shared_ptrs;
        Benchmark b("Shared pointers without make_shared");
        for (int i = 0; i < 1000; i++)
            shared_ptrs[i] = std::shared_ptr<Vector2>(new Vector2());
    }

    {
        std::array<std::unique_ptr<Vector2>, 1000> unique_ptrs;
        Benchmark b("Unique pointers");
        for (int i = 0; i < 1000; i++)
            unique_ptrs[i] = std::make_unique<Vector2>();
    }
}

void ExecuteBenchmark()
{
    BenchmarkSimpleLoop();
    BenchmarkSharedPointer();
}
