#include <iostream>
#include <string>
#include <vector>

void AutoDeclarations()
{
    int a = 5;

    auto b = 6; // int 
    auto c = a; // int

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    auto text1 = "Hello"; // const char*
    std::string text2 = "Hi";
    auto text3 = text2; // std::string

    std::cout << "text1: " << text1 << std::endl;
    std::cout << "text2: " << text2 << std::endl;
    std::cout << "text3: " << text3 << std::endl;
}

// if the return type is changed to char* the auto used variables that used this function would continue to work
static std::string GetName()
// static char* GetName()
{
    return "Jhow";
}

void AutoInFunctionReturns()
{
    std::string name = GetName(); // Valid
    auto name2 = GetName(); // Valid
}

void AutoInLoopsIterators()
{
    std::vector<std::string> strings;
    strings.push_back("something");
    strings.push_back("another thing");
    strings.push_back("something else");

    // for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    for(auto it = strings.begin(); it != strings.end(); it++) // works the same
    {
        std::cout << *it << std::endl;
    }
}

void AutoReferences()
{
    int a = 5;
    int& b = a;
    
    auto ref1 = b; // Copies the value, not reference it, even tough the value it is copying is a reference
    auto& ref2 = b; // Successfully references it

    a = 10;

    std::cout << "ref1: " << ref1 << std::endl; // 5
    std::cout << "ref2: " << ref2 << std::endl; // 10
}

void ExecuteAuto()
{
    AutoDeclarations();
    AutoInFunctionReturns();
    AutoInLoopsIterators();
    AutoReferences();
}
