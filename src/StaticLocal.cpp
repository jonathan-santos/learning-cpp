#include <iostream>

// Basically local statics are static variables local to functions that are shared between function executions

void IncreaseValueNonStatic()
{
    int i = 0;
    i++;
    std::cout << "NonStatic[i]: " << i << std::endl;
}

void IncreaseValueStatic()
{
    static int i = 0;
    i++;
    std::cout << "Static[i]: " << i << std::endl;
}

void ExecuteStaticLocal()
{
    IncreaseValueNonStatic();
    IncreaseValueNonStatic();
    IncreaseValueNonStatic();
    std::cout << std::endl;
    IncreaseValueStatic();
    IncreaseValueStatic();
    IncreaseValueStatic();
}
