#include <iostream>
#include <string>

using String = std::string; // Syntax sugar to improve the writing of code using standard library string

// The C language doesn't have a proper String data type. It has syntax sugar in the form of "" (double quotes) where the text inside is transformed into an array of chars. This array reserves a memory address, that is why you cant change the pointer, that's why its a convention to make it const. You can't change individual characters in the string, but you can change the whole string if you want. It is raw, not having any methods to help use it. But it is stack allocated, so you don't need to delete it manually
// The C++ standard library string is a proper type. Strings built on it can have their individual characters changed and they have various methods to help use them. To use it you need to #include <string>
void CStyleString()
{
    const char* text = "Hello world!";
    //const char name[13] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!' }; // It is the same as the line above
    text = "Hello there"; // Valid
    //text[0] = "h"; // Invalid. This will cause an error
    std::cout << text << std::endl; // The default <iostream> can output c style string out of the box
}

void CppStandardString()
{
    std::string text = "Something"; // Default string declaration. The std::string constructor takes a const char array
    String otherText = "Other something"; // Utilizing syntax sugar. Same functionality
    text[0] = 's';
    text.append("!");
    std::cout << text << std::endl;
}

void StringConcatenation()
{
    //std::string concatenatedString = "A " + "Name"; // Invalid. Because you are trying to "Unite" two const char arrays
    std::string concatenatedString = "A " + std::string("name"); // Valid

    std::string concatenatedString2 = "Another ";
    concatenatedString += "name";
}

void DifferentTypesOfStrings()
{
    // C Style
    const char* char8Bit = "Jhow"; // UTF8 (8 bit wide) character composed string
    const char* char8Bit2 = u8"Jhow"; // The default character is 8 bit and you can optionally prefix it if you want to enforce it
    const wchar_t* charWide =  L"Jhow"; // UTF-16LE (16 bit wide) character composed string (Native type on Windows Operating Systems)
    // C++11 new char types
    const char16_t* char16Bit = u"Jhow"; // UTF16 (16 bit wide) character composed string
    const char32_t* char32Bit = U"Jhow"; // UTF32 (32 bit wide) character composed string

    // C++ std string style
    std::string string8Bit = "Jhow";
    std::wstring stringWide = L"Jhow";
    std::u16string string16Bit = u"Jhow";
    std::u32string string32Bit = U"Jhow";
}

// C++ 14 feature
void StringLiterals()
{
    using namespace std::string_literals; // Gives us a number of functions for convenience

    // Better concatenation
    std::string concatenatedString = "A "s + "name";

    // Ignore escape characters
    std::string ignoredEscape = R"(something \n something)";
    std::string multiLineWithoutEscape = R"(line 1
line 2
line 3)";

    std::cout << ignoredEscape << std::endl;
}

void ExecuteStrings()
{
    CStyleString();
    CppStandardString();
    StringConcatenation();
    DifferentTypesOfStrings();
    StringLiterals();
}
