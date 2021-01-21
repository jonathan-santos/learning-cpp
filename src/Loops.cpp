#include <iostream>

void ForLoop()
{
    for (int i = 0; i < 10; i++) //Yes, you can do without brackets
        std::cout << "for[i]: " << i << std::endl;

    std::cout << "End of for loop" << std::endl << std::endl;
}

void WhileLoop()
{
    int i = 0;
    while (i < 10)
    {
        std::cout << "while[i]: " <<  i << std::endl;
        i++;
    }

    std::cout << "End of while loop" << std::endl << std::endl;
}

void DoWhileLoop()
{
    int i = 0;
    do
    {
        std::cout << "do while[i]: " <<  i << std::endl;
        i++;
    } while (i > 0 && i < 10);

    std::cout << "End of do while loop" << std::endl << std::endl;
}

void BreakLoop()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
            break;
        std::cout << "for (will break at 5) [i]: " << i << std::endl;
    }

    std::cout << "End of break loop" << std::endl << std::endl;
}

void ContinueLoop()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
            continue;
        std::cout << "for (will skip 5) [i]: " << i << std::endl;
    }

    std::cout << "End of continue loop" << std::endl << std::endl;
}

void ExecuteLoops()
{
    ForLoop();
    WhileLoop();
    DoWhileLoop();
    BreakLoop();
    ContinueLoop();
}
