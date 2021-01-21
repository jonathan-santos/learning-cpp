#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;

static void SomeFunctionToTest()
{
    for (int i = 0; i < 100; i++)
        std::cout << "Hello" << std::endl;
}

void HowLongFunctionExecutes(void (*func)())
{
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << "[FUNCTION] Executed in: " << duration.count() << " seconds" << std::endl;
}

// Using a struct/class
struct Timer
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer(void (*func)())
    {
        start = std::chrono::high_resolution_clock::now();
        func();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "[STRUCT] Executed in: " << duration.count() << " seconds" << std::endl;
    }
};

void ExecuteTiming()
{
    HowLongFunctionExecutes(SomeFunctionToTest);
    Timer testFunc(SomeFunctionToTest);
}
