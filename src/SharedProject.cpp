#include "Logging.h"

// To use the shared project as a statically linked library:
// g++ -c ./exampleLib/Logging.cpp -o ./exampleLib/Logging.o
// ar rvs ./exampleLib/liblogging.a ./exampleLib/Logging.o
// g++ ./source/Main.cpp -I./exampleLib -L./exampleLib -llogging

void ExecuteSharedProject()
{
    Logging::Log();
}
