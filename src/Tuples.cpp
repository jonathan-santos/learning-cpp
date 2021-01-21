#include <iostream>
#include <array>
#include <vector>
#include <tuple> // Necessary for the std::tuple but not for std::pair

std::string value1 = "Hello";
std::string value2 = " There";

std::string* ReturnArray()
{
    // std::string* array = new std::string[2] { value1, value2 };
    // return array;
    return new std::string[2] { value1, value2 };
}

std::array<std::string, 2> ReturnStdArray()
{
    // std::array<std::string, 2> array = { value1, value2 };
    // return array;
    return { value1, value2 };
}

std::vector<std::string> ReturnVector()
{
    // std::vector<std::string> vector = { value1, value2 };
    // return vector;
    return { value1, value2 };
}

struct StructValues
{
    std::string Value1;
    std::string Value2;
};

StructValues ReturnStruct()
{
    // StructValues values { value1, value2 };
    // return values;
    return { value1, value2 };
}

void AssignByPointers(std::string* outValue1, std::string* outValue2)
{
    *outValue1 = value1;
    *outValue2 = value2;
}

void AssignByReferences(std::string& outValue1, std::string& outValue2)
{
    outValue1 = value1;
    outValue2 = value2;
}

std::tuple<std::string, std::string> ReturnTuple()
{
    return std::make_pair(value1, value2);
}

std::pair<std::string, std::string> ReturnPair()
{
    return std::make_pair(value1, value2);
}

void ExecuteTuples()
{
    std::string* array = ReturnArray();
    std::cout << "Array: " << array[0] << array[1] <<std::endl;
    delete[] array;

    std::array<std::string, 2> stdArray = ReturnStdArray(); // Has the benefit of we knowing that there will be 2 values in the array
    std::cout << "Std Array: " << stdArray[0] << stdArray[1] <<std::endl;

    std::vector<std::string> vector = ReturnVector();
    std::cout << "Vector: " << vector[0] << vector[1] <<std::endl;

    StructValues structValues = ReturnStruct();
    std::cout << "Struct: " << structValues.Value1 << structValues.Value2 <<std::endl;

    std::string v1, v2;
    AssignByPointers(&v1, &v2);
    //AssignByPointers(nullptr, v2); // Useful when you only need one value
    std::cout << "References: " << v1 << v2 <<std::endl;

    std::string v3, v4;
    AssignByReferences(v3, v4);
    std::cout << "References: " << v3 << v4 <<std::endl;

    std::tuple<std::string, std::string> tuple = ReturnTuple();
    std::cout << "Tuples: " << std::get<0>(tuple) << std::get<1>(tuple) << std::endl;

    std::pair<std::string, std::string> pair = ReturnPair();
    std::cout << "Pair: " << pair.first << pair.second << std::endl;
}
