#include <iostream>
#include <any>

// It's a C++17 feature
// Must include <any> header file

void CreatingAny()
{
    std::any data;
    data = 2;
    data = "Hello";
    data = std::string("Jhow");
}

void CastingAny()
{
    std::any data;
    data = std::string("Hello");

    // data = 1; // Will result in error during cast
    // data = "Hello"; // Will result in error during cast as well, because the type in data is const char*

    std::string& value = std::any_cast<std::string&>(data);
    std::cout << "value in std::string: " << value << std::endl;
}

void ExecuteAny()
{
    CreatingAny();
    CastingAny();
}
