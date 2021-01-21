#include <iostream>
#include <vector>
#include <unordered_map>

void VectorIterator()
{
    std::vector<int> values = { 1, 2, 3, 4, 5 };

    // Classic for loop
    // for (int i = 0; i < values.size(); i++)
    //     std::cout << values[i] << std::endl;

    // Range based for loop (C++11)
    // For the range based loop to work the class using it (vector in this case) needs to have a iterator implemented
    // for (int value : values)
    //     std::cout << value << std::endl;

    // This is how the range based for loop works behind the scenes, it's just syntax sugar
    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
        std::cout << *it << std::endl;
}

void UnorderedMapIterator()
{
    using ScoreMap = std::unordered_map<std::string, int>;
    ScoreMap map;
    map["Key"] = 10;
    map["Jhow"] = 5;
    map["C++"] = 1;

    // for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
    // {
    //     auto& key = it->first;
    //     auto& value = it->second;
    //     std::cout << "[" << key << "]: " << value << std::endl;
    // }

    // The range based for loop also works for the unordered list
    // for (auto kv : map) // kv stands for key value
    //     std::cout << "[" << kv.first << "]: " << kv.second << std::endl;

    for (auto [key, value] : map) // If you are using C++17 you can also use structured bindings 
        std::cout << "[" << key << "]: " << value << std::endl;
}

void ExecuteIterators()
{
    VectorIterator();
    UnorderedMapIterator();        
}
