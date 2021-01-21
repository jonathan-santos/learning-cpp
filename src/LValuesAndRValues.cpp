#include <iostream>

int GetValue()
{
    return 10;
}

int& GetValueReference()
{
    static int value = 10;
    return value;
}

void SetValue(int value) { }
void SetValueByReference(int& value) { }
void SetValueByRValueReference(int&& value) { }
void SetValueByConstReference(const int& value) { }

void PrintNameByReference(std::string& value) { }
void PrintNameByRValueReference(std::string&& value) { }
void PrintNameByConstReference(const std::string& value) { }

void LValuesAndRValuesExamples()
{
    int i = 10;
    // In this case "i" is a lvalue (because it is on the left side of the statement, before the =)
    // And "10" is the rvalue (because it is in the right side of the statement, after the =)
    // The lvalue is a location in memory, which can contain a value
    // The rvalue is just a value, and it can't contain a storage or location in memory
    //10 = i; // Invalid. Rvalues can't contain information

    int j = i;
    // In this case, both the j and i are lvalues, because they are locations in memory which contain a value
    i = j; // Valid, because lvalues can contain other lvalues

    j = GetValue();
    // In this case the k is a lvalue and GetValue is a rvalue, because it doesn't have a location or storage
    //GetValue() = i; // Invalid. RValues can't contain information

    GetValueReference() = 15; // Valid. Because this contain a storage location inside it (it returns a reference to the value inside it), it is a lvalue
    std::cout << "GetValueReference(): " << GetValueReference() << std::endl; // 15

    SetValue(10); // Valid. It accepts a value, so a rvalue is valid 
    SetValue(i); // Valid. It accepts a value, so passing a lvalue is in fact passing the value inside of it

    SetValueByReference(i); // Valid. Because it wants a reference to a value, a lvalue
    //SetValueByReference(10); // Invalid. Because it wants a reference to a value, a lvalue, so it doesn't work

    SetValueByRValueReference(10); // Valid. Because it wants a reference to a rvalue
    // SetValueByRValueReference(i); // Invalid. Because it wants a reference to a rvalue, i being a lvalue doesn't compile

    // const references accept both lvalues and rvalues
    SetValueByConstReference(i); // Valid
    SetValueByConstReference(10); // Valid

    std::string firstName = "Jonathan ";
    std::string lastName = "Santos";
    std::string fullName = firstName + lastName;
    // In this case all the values before "=" are lvalues and all values after "=" are rvalues
    // firstName + lastName is a rvalue because it is a operation which returns a temporary rvalue, a new string containing both the values of firstName and lastName

    PrintNameByReference(fullName); // Valid. Because it wants a reference to a value, a lvalue
    // PrintNameByReference(firstName + lastName); // Invalid. Because it wants a reference to a value, a lvalue, and the + operation returns a temporary rvalue

    PrintNameByRValueReference(firstName + lastName); // Valid
    // PrintNameByRValueReference(fullName); // Invalid. Because it wants a reference to a rvalue, fullName being a lvalue doesn't compile

    PrintNameByConstReference(fullName); // Valid
    PrintNameByConstReference(firstName + lastName); // Valid

    // This is why various functions accept a const reference as parameters, because it allows the use of rvalues as parameters
}

void ExecuteLValuesAndRValues()
{
    LValuesAndRValuesExamples();
}
