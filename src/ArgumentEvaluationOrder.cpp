#include <iostream>

void PrintSum(int a, int b)
{
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

void ExecuteArgumentEvaluationOrder()
{
    int value = 0;
    PrintSum(value++, value++); // 1 + 0 = 1 in debug, 0 + 0 = 0 in release
    PrintSum(++value, ++value); // 4 + 4 = 8 in debug, 4 + 4 = 8 in release
    // Undefined behavior. Since there is no specification of what should happen in this situation in the C++ standard, it is compiler dependant
    // But, in C++ 17 there is a specification defining that the two operations (value++) cannot be done at the same time, meaning that they should be done one after the other. But the order is not defined in the specification
}
