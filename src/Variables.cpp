#include <string>

using String = std::string; // Trick to make string look better

void ExecuteVariables()
{
    char character = 'A';
    short smallNumber = 10;
    int integer = 0;
    unsigned int oneByteLargerInt = 101; // Remove the byte for the negative sign, increasing the ammout exponentially. Can only be positive
    long longNumber = 10010101;
    long long veryLongNumber = 100101010101;
    float decimalNumber = 10.5f; // For float it needs to have f at the end, otherwise it's technically a double
    double largerDecimalNumber = 10.5; // Easier to use and has more capacity, but consumes more memory
    bool condition = 1; // true, false, 0 == false, !0 == true
    const char* text = "Something";
    std::string string = "Other something";
    String otherString = "Another string"; //Works the same way as the above
}
