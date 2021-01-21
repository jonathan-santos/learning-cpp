#include <iostream>

// Code breakpoints are what the name implies, they are a way to raise a breakpoint from inside the code. The method to raise a breakpoint is compiler dependant, with gcc being __builtin_trap()
// The method to execute a breakpoint in Visual C++ compiler is __debugbreak()

void ExecuteBreakpoints()
{
    int i = 0;

    if (i)
        std::cout << "All right" << std::endl;
    else
        __builtin_trap();
}
