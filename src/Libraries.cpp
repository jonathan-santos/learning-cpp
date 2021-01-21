// #define GLFW_DLL // Needed for use of GLFW with dynamic linking. Not necessary for all dynamic linked libraries, the library itself may or may not need defined preprocessors. May also be added in compilation command as a flag (-DGLFW_DLL, with a optional space)

#include <iostream>
#include <GLFW/glfw3.h>
// #include "../dependencies/GLFW/include/GLFW/glfw3.h" // If you don't want to add the -I flag or put the library in your computer includes, you can #include the include file directly
// extern "C" int glfwInit(); // You can of course create your own definition of the library functions, lifting the need to #include the header file. But this is a C library (look at the .h definition up), so you need to add the extern keyword and the "C" string before the function definition, otherwise it won't compile

// Libraries are pieces of reusable code you can create or use to aid you in create programs.
// Example of C++ library: https://glfw.org
// When downloading a library, you gotta download the one corresponding to your FINAL USER machine. So if the final user binary should be for 32 bit computers, you need to use the 32 bit library binary for the project
// The libraries file you download always has two important folders in them. The include directory contains the header files for use of the library. The different lib folders contain the prebuilt (or not) binaries for use of the library.
// The library binary you'll use in your project depends on what is your DEVELOPMENT machine final executable will be. So if you are in a Windows Machine using Visual Studio 2015, get the library for it, it you are using Mingw-64 get the binaries for mingw-64.
// In C++ there are two ways of using libraries, by statically linking them or by dynamically linking them
// GLFW is a library that allows us to link dynamically or statically

// Linking (indenpendent if it is statically or dynamically)
// To link your library to the project, add the library include in your DEVELOPMENT machine include path or add the flag -I to your compiler passing as a argument the path to your library include directory. Ex: -I./dependencies/GLFW/include (The argument can be separated by a space or not)
// With only the include step out of the way, your project can be successfully compiled, but will break on the link step, because the linker only has the symbol declarations(from the header files), but won't be able to find the definition of symbols. To fix that you need to use compiler flags defining wich libraries (and where) to use:
// Using the -l flag with a parameter as the path to the library the project needs: -l./dependencies/GLFW/lib/glfw3 , without the lib in the start of the name and  without the extension at the end (in this case the desired library binary file was libglfw3.a) and the parameter can be optionally separated by a space (-l glfw3 or -lglfw3 are valid) at least in mingw-64 compiler. This needs to be done by all the libraries binaries you'll need
// Or
// Using the -L flag, you can point the path to the library binaries, useful when needing to use various binaries: -L./dependencies/GLFW/lib (The parameter can be optionally separated by a space as well)
// Now the -l flag only needs the name of the binarie, not the path anymore -lglfw3 (Again the parameter can be optionally separated by a space)
// Even if the binary is not in the -L defined library path, if it is in the default compiler libraries, you can pass it without the path as well, exs: -lgdi32 -lopengl32 -luser32 -lkernel32 (Default libraries in the Mingw-64 compiler)
// The -l flag gets the binary file (in the case of mingw-64 the .a compiled ones, in Visual C++ the .lib compiled ones) and automatically removes the lib from the start of the name and the the extension at the end(exs: to get libglfw3.a put -lglfw3 and to get libglfw3dll.dll put -lglfw3dll) at least in mingw-64 compiler
// Some libraries may need preprocessor definitions for compilation (in static or dynamic or both) to work. In the case of GLFW, in the dynamic compilation it is needed to use a preprocessor definition (-DGLFW_DLL to be more exact) which can be done by adding it in the top of the main file with #define GLFW_DL, or as a flag to the compile command with -DGLFW_DLL (space between flag and parameter optional). In some cases (like this with the GLFW3 library) this preprocessor definitions are actually optional, but highly recommended, as in this case they allow for compile time optimizations (in doubt, do what the documentation mandates)
// IMPORTANT: the order of linking libraries (with the -l flag) MATTERS, in this case for example, if adding -lgdi32 before -lglfw3 the compilation will break. For example: there was a case for me when using the library glew file glfw.

// Static Linking
// Static linking libraries basically bundles them with your final executable file. Meaning that the library is linked to your code during compile time. It is technically faster, because during linking it can create optimizations
// The (lib)glfw3(.a) library binary is the static version of glfw3 library. So to successfully statically link it with our project, you only need to add the -l flag pointing to it (-lglfw3)
// The gdi32 library binary is needed in this case because of linking errors to the glfw3 library binary using the Mingw-64 compiler specifically, Visual C++ didn't need them for example
// With this project using the GLFW library and the Mingw-64 compiler as a example, the final command would be: g++ ./src/*.cpp -o ./bin/main.exe -I./dependencies/GLFW/include -L./dependencies/GLFW/lib -l glfw3 -lgdi32
// And thus, the project can be successfully compiled and will result in the binary main.exe with all the necessary libraries binaries (glfw3, dgi32) builtin. This results in a single file executable which at this point is 344Kb in size

// Dynamic Linking
// Dynamic linking libraries basically don't link them at compile time, but at runtime, during the application launch. Meaning that the library binary file (those famous .dll files at the side of the .exe in windows) is separated from the final executable file and loaded during the application dynamically. It is technically slower
// The (lib)glfw3dll(.a) library binary is the dynamic version of glfw3 library. So to successfully statically link it with our project, you only need to add the -l flag pointing to it (-lglfw3dll)
// After adding the dynamic library at the compilation command the project will successfully compile, but will end in a run time error
// The reason why there is a runtime error in this case if because you need to have the .dll library binary file in the same directory as the final executable, for it to link to at runtime
// The gdi32 library binary is needed in this case because of linking errors to the glfw3 library binary using the Mingw-64 compiler specifically, Visual C++ didn't need them for example
// And thus, the project can be successfully compiled and will result in the binary main.exe with only your code (and #includes and dgi32) in it, the glfw3.dll file will include the code for it. This results in a executable with 84Kb in size and a glfw3.dll with 244Kb in size (84kb + 244kb = 328kb total)

// In the end, your code will differ very little from the different methods of linking libraries, it's your project structure (and commands) that will change.

void InitLibrary()
{
    int isGlfwSuccessfullyInitiating = glfwInit(); // This function returns if GLFW is initiating successfully or not, with 1 meaning success and 0 error 
    std::cout << "Is Glfw successfully initiating: " << isGlfwSuccessfullyInitiating << std::endl; // Will result in 1 hopefully
}

void ExecuteLibraries()
{
    InitLibrary();
}
