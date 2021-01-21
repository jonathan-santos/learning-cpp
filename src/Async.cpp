#include <iostream>
#include <future>
#include <vector>
#include <thread>

#include "Benchmark.h"

// It's a C++11 feature
// Must include <future> header file

void SlowFunction()
{
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);
    std::cout << "Slow function ended\n";
}

void SyncLoopOfSlowFunctions()
{
    for (int i = 0; i < 5; i++)
        SlowFunction();
}

void AsyncLoopOfSlowFunctions()
{
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 5; i++)
        futures.push_back(std::async(std::launch::async, SlowFunction));
}

void SlowFunctions()
{
    {
        Benchmark b("SYNC Loop of slow functions (5x, 1s each)");
        SyncLoopOfSlowFunctions();
    }

    std::cout << "\n";

    {
        Benchmark b("ASYNC Loop of slow functions (5x, 1s each)");
        AsyncLoopOfSlowFunctions();
    }
}

int SlowArrayGet(int i)
{
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);
    return i;
}

void SyncSlowGetArrayValues()
{
    for (int i = 0; i < 5; i++)
        std::cout << SlowArrayGet(i) << ",";
    std::cout << "\n";
}

void AsyncSlowGetArrayValues()
{
    std::vector<std::future<int>> f_ArrayValues;
    for (int i = 0; i < 5; i++)
        f_ArrayValues.push_back(std::async(std::launch::async, SlowArrayGet, i));

    for (int i = 0; i < 5; i++)
        std::cout << f_ArrayValues[i].get() << ",";

    std::cout << "\n";
}

void SlowArrays()
{
    {
        Benchmark b("SYNC Loop of slow array get (5x, 1s each)");
        SyncSlowGetArrayValues();
    }

    std::cout << "\n";

    {
        Benchmark b("ASYNC Loop of slow array get (5x, 1s each)");
        AsyncSlowGetArrayValues();
    }
}

void ExecuteAsync()
{
    SlowFunctions();
    std::cout << "\n";
    SlowArrays();
}
