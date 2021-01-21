#include <iostream>

void PrintHelloThere()
{
    std::cout << "Hello there" << std::endl;
}

void PrintInteger(int value)
{
    std::cout << value << std::endl;
}

template <typename T>
void PrintSomething(T value)
{
    std::cout << value << std::endl;
}

void SavingFunctionsInVariables()
{
    // typedef void(*PrintHelloThereFunction)();
    // PrintHelloThereFunction function = PrintHelloThere;
    // void(*function)() = &PrintHelloThere;
    auto function = &PrintHelloThere;
    function(); // Hello there

    // typedef void(*PrintIntegerFunction)(int);
    // PrintIntegerFunction function2 = PrintInteger;
    // void(*function2)(int) = &PrintInteger;
    auto function2 = &PrintInteger;
    function2(10); // 10

    //auto function3 = &PrintSomething; // Invalid. Template functions are not valid types, so they cannot be used as pointers
}

template <int size>
void ForEach(int* values, void (*func)(int))
{
    for (int i = 0; i < size; i++)
        func(values[i]);
}

void UsingAFunctionAsAParameter()
{
    int values[5] = { 1, 2, 3, 4, 5 };
    ForEach<5>(values, PrintInteger);


    ForEach<5>(values, [](int value) { std::cout << value << std::endl; }); // lambda function
    // auto lambdaFunc = [](int value) { std::cout << value << std::endl; };
    // ForEach<5>(values, lambdaFunc);
}

void ExecuteFunctionPointers()
{
    SavingFunctionsInVariables();
    UsingAFunctionAsAParameter();
}
