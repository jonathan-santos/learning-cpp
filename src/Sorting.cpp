#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // Include various sorting functions

// To use the C++ sort, we need to first import <algorithm>

void PrintVector(std::vector<int> values)
{
    for (int i = 0; i < values.size(); i++)
        std::cout << values[i] << " ";

    std::cout << std::endl;
}

void DefaultAscendingSort(std::vector<int> values)
{
    std::sort(values.begin(), values.end()); // By default it sorts in ascending order
    PrintVector(values);
}

void ManualAscendingSort(std::vector<int> values)
{
    std::sort(values.begin(), values.end(), [](int a, int b)
    {
        return a < b;
    });

    PrintVector(values);
}

void GreaterSort(std::vector<int> values)
{
    std::sort(values.begin(), values.end(), std::greater<int>());
    PrintVector(values);
}

void ExecuteSorting()
{
    std::vector<int> values = { 3, 5, 1, 4, 2 };
    PrintVector(values); // 3 5 1 4 2
    DefaultAscendingSort(values); // 1 2 3 4 5
    ManualAscendingSort(values); // 1 2 3 4 5
    GreaterSort(values); // 5 4 3 2 1
}
