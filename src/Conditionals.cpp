#include <iostream>

void SimpleCondition()
{
    bool condition = 1 == 1;

    if(condition)
    {
        std::cout << "1 is equal to 1" << std::endl;
    }
}

void IfAndElse()
{
    if(1 == 2)
    {
        std::cout << "1 is equal to 2" << std::endl;
    }
    else
    {
        std::cout << "1 is not equal to 2" << std::endl;
    }
}

void ElseIf()
{
    if (false)
    {
        std::cout << "This if is not gonna work" << std::endl;
    }
    else if(true)
    {
        std::cout << "The if didn't work, but the else if did" << std::endl;
    }    
}

void NoBrackets()
{
    if(true)
        std::cout << "You can write conditionals without brackets" << std::endl;
    else
        std::cout << "You cannot write conditionals without brackets" << std::endl;
}

void Ternary()
{
    const char* ternary = true ? "Yes" : "No";
    std::cout << "Is there a ternary operator in C++? " << ternary << std::endl;
}

void ExecuteConditionals()
{
    SimpleCondition();
    IfAndElse();
    ElseIf();
    NoBrackets();
    Ternary();
}
