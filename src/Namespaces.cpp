#include <iostream>

// Namespaces are a c++ feature that allows to declare variables, classes and functions together inside a unit (the namespace) in order to prevent naming conflicts with your code or other people code (libraries and such)
// In order to use a namespace you just need to write namespace namespaceName { // write your code here } and then that code is now inside the namespace, needing to append the namespace before the code you need to use
// Now to access namespace members you use the :: operator (scope resolution operator)

// using namespace apple; // Valid. Now you don't need to append apple:: before using it's members like print

namespace apple {
    void print(const char* text)
    {
        std::cout << text << std::endl;
    }
}

namespace orange {
    void print(const char* text)
    {
        std::cout << "text: " << text << std::endl;
    }

    namespace something { // Yes, you can nest namespaces
        void SaySomething() {
            std::cout << "SOMETHING" << std::endl;
        }
    }
}

void DefaultNamespaceUsage()
{
    apple::print("Hello"); // Hello
    orange::print("Hello"); // text: Hello
    orange::something::SaySomething(); // text: SOMETHING
}

// using namespace namespaceName allows us to forgo using the namespaceName:: before the namespace members, can be done inside a scope or globally in file
void UsingNamespace()
{
    {
        using namespace apple;
        //using namespace orange; // Valid, but will result in an error, because the two namespaces have a definition of void print(const char*). Try to avoid multiple using namespace statements, as they can very easilly (as in this case) result in an error

        print("Hello"); // Hello;        
    }

    {
        using namespace orange::something;
        SaySomething(); // SOMETHING
    }

    {
        using namespace orange;
        print("Hello"); // text: Hello
        something::SaySomething(); // SOMETHING. You used namespace orange, and now have access to it's members without the prefix apple::, including it's nested namespaces

        using namespace something;// If desired, you can now use the nested namespace as well
        SaySomething(); // SOMETHING
    }

    {
        using apple::print; // You can also only use specific members of a namespace but omitting the namespace keyword and placing them after the namespace name and the :: operator
        print("Hello"); // Hello
    }
}

void NamespaceAliases()
{
    namespace a = apple;
    namespace ORANGE = orange;

    a::print("Hello"); // Hello
    ORANGE::print("Something"); // text: Something
}

void ExecuteNamespaces()
{
    DefaultNamespaceUsage();
    UsingNamespace();
    NamespaceAliases();
}
