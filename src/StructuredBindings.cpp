#include <iostream>
#include <tuple>
#include <string>

// It's a C++17 alternative to tuples to deal with multiple return values 

static std::tuple<std::string, int> CreatePersonTuple()
{
    return { "Jhow", 22 };
}

void UseTupleClassic()
{
    auto person = CreatePersonTuple();
    std::cout << std::get<0>(person) << " is " << std::get<1>(person) << " years old" << std::endl;
}

void UseTupleTie()
{
    std::string name;
    int age;
    std::tie(name, age) = CreatePersonTuple();
    std::cout << name << " is " << age << " years old" << std::endl;
}

void UseStructuredBinding()
{
    auto[name, age] = CreatePersonTuple();
    std::cout << name << " is " << age << " years old" << std::endl;
}

void ExecuteStructuredBindings()
{
    UseTupleClassic();
    UseTupleTie();
    UseStructuredBinding();
}
