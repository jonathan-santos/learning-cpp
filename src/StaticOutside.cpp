#include <iostream>

// Static (outside classes and structs) basically affects the visibility of variables and Functions in translation units

//int S_Value = 10; //Will result in an error, because it already was defined (as static) in the translation unit (trough the StaticOutside2.cpp file)
static int S_Value = 10; // Valid. Because static in global scope means that this variable is exclusive to this translation unit
//int S_Value2 = 20; // Will result in an error, because it already was defined in the translation unit (trough the StaticOutside2.cpp file)
extern int S_Value2; // Valid. It is getting the value from another translation unit (through the StaticOutside2.cpp file)
//extern int S_Value3; // Will result in an error, as it is expecting a value S_Value3 in some translation unit, but there is none anywhere

//void FunctionFromStaticHeader() { } // Will result in an error. The same that applies to variables in global context applies to functions
void FunctionFromStaticOutside(); // The difference with functions is that it does not need the extern keyword, only the Base of the function
void FunctionFromStaticOutside2() { } // Valid. Because the other FunctionFromStaticHeader2 definition, in the file StaticOutside2.cpp is marked as static

void ExecuteStaticOutside()
{
    std::cout << "S_Value: " << S_Value << std::endl; // 10
    std::cout << "S_Value2: " << S_Value2 << std::endl; // 20
}
