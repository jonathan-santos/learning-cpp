#include <iostream>
#include <memory>

// Smart pointers are a special type of pointer specialized to be used with heap values where on end of scope (depending on type of pointer) the value they hold is automatically deleted. Preventing a memory leak
// ManualSmartPointer is just an example of how a smart pointer works, in general it is recommended to use one of the builtin ones in C++ bellow
// UniquePointer: A pointer where it automatically deletes the content once the scope of the pointer ends. Doesn't have a overhead. Can't be copied or passed to a function
// SharedPointer: A pointer where it automatically deletes the content once ALL the shared pointers are out of scope. It does have a overhead, because the shared pointers need to be reference counted. Can be copied or passed to a function. Can result in memory leak if not careful
// WeakPointer: Similar to SharedPointer, but it doesn't count to the reference counting of the SharedPointer, meaning it can't memory leak and if all shared pointers are out of scope, the weak pointer will point to null

class EntitySmart
{
public:
    const char* Name;
    EntitySmart(const char* name) : Name(name) { std::cout << Name << ": Entity created" << std::endl; }
    ~EntitySmart() { std::cout << Name << ": Entity destroyed" << std::endl; }
};

class ManualSmartPointer
{
private:
    EntitySmart* m_Value;
public:
    ManualSmartPointer(EntitySmart* value) : m_Value(value) { }

    ~ManualSmartPointer()
    {
        std::cout << "Manual smart pointer is out of scope, deleting itself and the value it is holding" << std::endl;
        delete m_Value;
    }

    EntitySmart& Get()
    {
        return (*m_Value);
    }
};

void UseDefaultPointer()
{
    int* ptr = new int(5);
    std::cout << "DefaultPointer value: " << *ptr << std::endl;
    delete ptr;
}

void UseManualSmartPointer()
{
    ManualSmartPointer ptr(new EntitySmart("ManualSmartPointer"));    
}

void UseUniquePointer()
{
    std::unique_ptr<EntitySmart> ptr = std::make_unique<EntitySmart>("UniquePointer");
    //std::unique_ptr<EntitySmart> ptr2 = ptr; // Invalid. Unique pointer can't be copied or referenced
} // Value is deleted. Because ptr is out of scope

void UseSharedPointer()
{
    std::shared_ptr<EntitySmart> ptr0;
    {
        std::shared_ptr<EntitySmart> ptr1 = std::make_shared<EntitySmart>("SharedPointer");
        ptr0 = ptr1;
    } // Although the ptr1 is declared in this scope, the value is not deleted yet, because ptr0 is referencing it and it is not yet out of scope
} // Value is deleted. Because ptr0 (the second shared pointer to the value) is out of scope

void UseWeakPointer()
{
    std::weak_ptr<EntitySmart> ptr;
    {
        std::shared_ptr<EntitySmart> sharedPtr = std::make_shared<EntitySmart>("WeakPointer");
        ptr = sharedPtr;
    } // Value is deleted. Because altough ptr is not out of scope, it is a weak pointer, so since sharedPtr is the only shared reference to value, the value is deleted
}

void ExecuteSmartPointers()
{
    UseDefaultPointer();
    std::cout << std::endl;
    UseManualSmartPointer();
    std::cout << std::endl;
    UseUniquePointer();
    std::cout << std::endl;
    UseSharedPointer();
    std::cout << std::endl;
    UseWeakPointer();
}
