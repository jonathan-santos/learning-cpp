#include <iostream>

// Anonymous functions
void CreatingLambdas()
{
    auto hello = []() { std::cout << "Hello there" << std::endl; };
    hello();

    int a = 5;

    //auto lambdaDefault = []() { std::cout << "a: " << a << std::endl; }; // Invalid .The lambda has no access to the function Lambdas() scope
    auto lambdaWithEqual = [=]() { std::cout << "a: " << a << std::endl; }; // With the = in the capture group of the lambda (the []), it will have access to the symbols in the scope of the function calling it as values
    auto lambdaWithAnd = [&]() { std::cout << "a: " << a << std::endl; }; // With the & in the capture group of the lambda, it will have access to the symbols in the scope of the function calling it as references
    auto lambdaWithValue = [a]() { std::cout << "a: " << a << std::endl; }; // With the a in the capture group of the lambda, it will have access to the a variable (and only it) as a value
    auto lambdaWithReference = [&a]() { std::cout << "a: " << a << std::endl; }; // With the &a in the capture group of the lambda, it will have access to the a variable (and only it) as a reference

    lambdaWithEqual();
    lambdaWithAnd();
    lambdaWithValue();
    lambdaWithReference();
}

void ExecuteLambdas()
{
    CreatingLambdas();
}
