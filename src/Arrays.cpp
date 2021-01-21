#include <iostream>
#include <array> // C++11 Standard library Array (not the standard C++ array, a "new" one)

// The standard C++ array is very raw. Having very simple functionality and no methods inside of it to know the size of arrays, do splices, add values, etc.
// The C++ 11 standard library array can be used the same way as the standard C++ array, but it has a few methods to help to use it

void CreateArrayInStack()
{
    int listOf5Numbers[5]; // To create a array in stack: typeOfArray varName[sizeOfArray];
    listOf5Numbers[0] = 1; // To access a value of an array: varName[index];
    listOf5Numbers[1] = 2;
    listOf5Numbers[2] = 3;
    listOf5Numbers[3] = 4;
    listOf5Numbers[4] = 5;
    //listOf5Numbers[5] = 6; // Valid. Trying to access out of index value in an array MAY (depending on the index, because it can try to access memory allocated to another variable) result in an error and close your program

    std::cout << "listOf5Numbers[0]: "  << listOf5Numbers[0] << std::endl; // 1
    
    std::cout << "listOf5Numbers: " << listOf5Numbers << std::endl; // 0x61fda0, the variable that holds the array itself is just a pointer
    for (int i = 0; i < 5; i++)
        std::cout << listOf5Numbers[i] << ", "; // 1, 2, 3, 4, 5, 
}

void CreateArrayInHeap()
{
    int* listOf10NumbersInHeap = new int[10]; // To create a array in heap
    for (int i = 0; i < 10; i++)
        listOf10NumbersInHeap[i] = i;
    delete[] listOf10NumbersInHeap; // To delete an array in the heap, you need to add [] symbol at the end of the delete keyword
}

void GetArraySize() // The "standard" array in C++ does not have a bultin way of getting the size of the array, to do that, you manually have to calculate the size of the array in bytes
{
    int array[5];
    int arraySize = sizeof(array)/sizeof(int);
    std::cout << "int array[5] size: " << arraySize << std::endl;
}

void Cpp11Array()
{
    std::array<int, 5> array; // To create C++11 array: std::array<typeOfArray, sizeOfArray> varName;
    for (int i = 0; i < 5; i++) // To use the array, it's the same as the standard array in C++
        array[i] = i;

    std::cout << "C++ 11 Array: ";
    for (int i = 0; i < 5; i++)
        std::cout << array[i] << ", "; // 0, 1, 2, 3, 4,

    std::cout << std::endl;
    std::cout << "C++ 11 array size: " << array.size() << std::endl;
}

void ExecuteArrays()
{
    CreateArrayInStack();
    CreateArrayInHeap();
    GetArraySize();
    Cpp11Array();
}
