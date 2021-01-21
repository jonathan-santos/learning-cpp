#include <iostream>

void CreateA1DimensionalArray()
{
    int* array = new int[50]; // Array of integers
    delete[] array;
}

void CreateA2DimensionalArray()
{
    int** array2d = new int*[50]; // Array of integer pointers

    for (int i = 0; i < 50; i++) // Allocated 50 arrays of integers, each inside one index in array2d
        array2d[i] = new int[50];

    for (int i = 0; i < 50; i++)
        delete[] array2d[i];
    delete[] array2d;
}

void CreateA3DimensionalArray()
{
    int*** array3d = new int**[50]; // Array of integer pointers

    for (int i = 0; i < 50; i++) // Allocated 50 arrays of pointers of integers, each inside one index in array3d
    {
        array3d[i] = new int*[50];

        for (int j = 0; j < 50; j++)  // Allocated 50 arrays of integers, each inside one index inside one index in array3d
        {
            // int** ptr = array3d[i];
            // ptr[j] = new int [50];
            array3d[i][j] = new int[50]; // The same thing as the two lines above
        }
    }

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
            delete[] array3d[i][j];

        delete array3d[i];
    }
    delete[] array3d;
}

void ExecuteMultidimensionalArrays()
{
    CreateA1DimensionalArray();
    CreateA2DimensionalArray();
    CreateA3DimensionalArray();

}
