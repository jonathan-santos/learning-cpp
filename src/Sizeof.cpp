#include <iostream>
#include <string>

// Show in bytes the size of types
void ExecuteSizeof()
{
    std::cout << "char: " <<  sizeof(char) << std::endl;                 //1
    std::cout << "short: " <<  sizeof(short) << std::endl;               //2
    std::cout << "int: " <<  sizeof(int) << std::endl;                   //4
    std::cout << "unsigned int: " <<  sizeof(unsigned int) << std::endl; //4
    std::cout << "long: " <<  sizeof(long) << std::endl;                 //8
    std::cout << "long long: " <<  sizeof(long long) << std::endl;       //8
    std::cout << "float: " <<  sizeof(float) << std::endl;               //4
    std::cout << "double: " <<  sizeof(double) << std::endl;             //8
    std::cout << "bool: " <<  sizeof(bool) << std::endl;                 //1
    std::cout << "const: " <<  sizeof(const char*) << std::endl;         //8
    std::cout << "std: " <<  sizeof(std::string) << std::endl;           //32
}
