#include <iostream>

#define DEBUG 1 // The DEBUG definition can be added inside the code of using a flag to the compiler -DDEBUG
//#define DEBUG 

// Macros are preprocessor commands used to automate code writing in C++
// They can be defined anywhere, but it is recommended (and a good idea) to write them ontop of the source code

#define WAIT std::cin.get()
#define WAIT2 std::cin.get();

#if 0 // useful for disabling pieces of code
#define CURLY { 
#endif

// Now you can make it so that during release builds there isn't any Logging to the console just by not defining DEBUG
// #ifdef DEBUG
#if DEBUG == 1
#define LOG(x) std::cout << x << std::endl // Almost like a function definition
// #elif defined(RELEASE)
#else
#define LOG(x)
#endif

// Also possible to define multiline macros (just add the \ to the end of the lines to break):
/*
#define HELLO void MultilineMacro()\
{\
     LOG("Hello from the multiline macro");\
}
*/

//HELLO

void ExecuteMacros()
// CURLY // the same as writing {
{
//     MultilineMacro();
    LOG("Hello there");
    WAIT; // Now is the same as writing std::cin.get(); Because during compilation WAIT is changed with it's value
    // WAIT2 // The macro already had a semicolen, so we didn't need to define it here
}
