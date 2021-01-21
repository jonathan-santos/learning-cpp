#include <iostream>

class EntityOnHeap
{
public:
    EntityOnHeap()
    {
        std::cout << "Entity created" << std::endl;
    }

    ~EntityOnHeap() // Destructor
    {
        std::cout << "Entity destroyed" << std::endl;
    }
};

// Even if a object is not supposed to be in the heap, if it has properties that will be on the heap, you need to define destructors that successfully delete those values. Otherwise, memory leak
class EntityWithValuesOnHeap
{
private:
    int* m_Values;
public:
    EntityWithValuesOnHeap()
    {
        m_Values = new int[50];
    }

    ~EntityWithValuesOnHeap()
    {
        std::cout << "Delete Entity with values on Heap" << std::endl;
        delete m_Values;
    }
};

void ExecuteHeap()
{
    int* a = new int(0); // To create something on the heap you just need to use the new keywoard with a constructor. It returns a pointer to the value, not the value itself
    *a = 5; // You can use heap allocated values normally just like stack allocated. The use is the same
    std::cout << *a << std::endl; // 5
    delete a; // You NEED to delete the heap allocated values manually, otherwise they will stay active, possibly resulting in a memory leak

    EntityOnHeap* e = new EntityOnHeap(); // With objects it's the same thing
    delete e;

    EntityWithValuesOnHeap e2; // Stack allocated values call delete automatically, so you don't need to worry about that
}
