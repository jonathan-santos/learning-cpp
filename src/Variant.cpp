#include <iostream>
#include <variant>

// It's a C++17 feature
// Must include <variant> header file

void BasicUsage()
{
    std::variant<std::string, int> data;
    data = "Cherno";
    //std::cout << data << std::endl; // Invalid. The compiler doesn't know what type the data is so it doesn't compile
    std::cout << std::get<std::string>(data) << std::endl;

    data = 15;
    // std::cout << std::get<std::string>(data) << std::endl; // Invalid. Will result in bad variant expection at runtime
    std::cout << std::get<int>(data) << std::endl;

    // data = false; // Valid
    // std::cout << std::get<bool>(data) << std::endl; // Invalid. Will result in bad variant exception, because this variant did not specify it could be bool
}

void IndexUsage()
{
    std::variant<std::string, int> data;
    data = "Hello";

    if (data.index() == 0)
        std::cout << std::get<std::string>(data) << std::endl;
    else
        std::cout << std::get<int>(data) << std::endl;
}

void GetIfUsage()
{
    std::variant<std::string, int> data;
    data = 30;

    //std::get_if returns a pointer, so to use the value dereference it
    if (auto value = std::get_if<std::string>(&data))
        std::cout << *value << std::endl;
    else if (auto value = std::get_if<int>(&data))
        std::cout << *value << std::endl;
}

// Variants when created basically reserve a space of memory the largest possible value type and 4 more bytes for the int index specifying which type it is using, so if we create a variant of string and int (in G++) it will have a size of 40 (int is 4, float is 4 and string is 32)
void SizeOfVariants()
{
    std::variant<std::string, float, int> data;
    std::cout << "int: " << sizeof(int) << std::endl; // 4
    std::cout << "float: " << sizeof(float) << std::endl; // 4
    std::cout << "std::string: " << sizeof(std::string) << std::endl; // 32
    std::cout << "variant of int and string: " << sizeof(data) << std::endl; // 40
}

void ExecuteVariant()
{
    BasicUsage();
    IndexUsage();
    GetIfUsage();
    SizeOfVariants();
}
