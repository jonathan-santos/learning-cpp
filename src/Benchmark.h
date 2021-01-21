#include <chrono>
#include <array>
#include <memory>

class Benchmark
{
private:
    const char* m_Name;
    std::chrono::high_resolution_clock::time_point m_Start, m_End;
public:
    Benchmark(const char* name);
    ~Benchmark();
};
