#include "pch.h"

// Precompiled headers are a way to reduce compile times in c++ projects.
// To use it you create a header file with the includes that you want precompiled, in this case pch.h
// Then you compile only it using g++: `g++ ./src/pch.h`, which will generate ./src/pch.gch. which is the precompiled version of it
// Now in the source files you wish to use the precompiled one, you don't need to change anything, when the compiler notices that you include a header which has a precompiled version, it will give preference to the precompiled version automatically

void ExecutePrecompiledHeaders()
{
    std::cout << "Precompiled Headers" << std::endl;
}
