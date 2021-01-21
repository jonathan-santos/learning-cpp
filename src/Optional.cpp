#include <iostream>
#include <fstream>
#include <string>
#include <optional>

// It's a C++17 feature
// Must include <optional> header file

std::string ReadFileCheckString(const std::string& filePath)
{
    std::ifstream stream(filePath);

    if (stream)
    {
        std::string result;
        std::string line;

        while(getline(stream, line))
            result += line;
        
        stream.close();
        return result;
    }
    
    return std::string();
}

void CheckResult()
{
    std::string data = ReadFileCheckString("./src/data.txt");
    if (data != "")
        std::cout << "File read successful: " << data << std::endl;
    else
        std::cout << "File read unsuccessful" << std::endl;
}

std::string ReadFileOutBool(const std::string& filePath, bool& outSuccess)
{
    std::ifstream stream(filePath);
    if (stream)
    {
        std::string result;
        std::string line;

        while(getline(stream, line))
            result += line;
        
        stream.close();
        outSuccess = true;
        return result;
    }
    
    outSuccess = false;
    return std::string();
}

void CheckOutBool()
{
    bool success = false;
    std::string data = ReadFileOutBool("./src/data.txt", success);
    if (success)
        std::cout << "File read successful: " << data << std::endl;
    else
        std::cout << "File read unsuccessful" << std::endl;
}

std::optional<std::string> ReadOptional(const std::string& filePath)
{
    std::ifstream stream(filePath);
    if (stream)
    {
        std::string result;
        std::string line;

        while(getline(stream, line))
            result += line;
        
        stream.close();
        return result;
    }
    
    return {};
}

void CheckOptional()
{
    // std::optional<std::string> data = ReadFileOutBool("./src/data.txt");
    auto data = ReadOptional("./src/data.txt");
    // if (data.has_value())
    if (data)
        std::cout << "File read successful: " << data.value() << std::endl;
    else
        std::cout << "File read unsuccessful" << std::endl;

    // If you want a default value: data.value_or("Something")
}

void ExecuteOptional()
{
    CheckResult();
    CheckOutBool();
    CheckOptional();
}
