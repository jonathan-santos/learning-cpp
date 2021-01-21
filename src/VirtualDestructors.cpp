#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base constructed" << std::endl; }
    virtual ~Base() { std::cout << "Base destroyed" << std::endl; }
};

class Derived : public Base
{
private:
    int* m_A;
public:
    Derived() { m_A = new int(5); std::cout << "Derived constructed" << std::endl; }
    ~Derived() { delete m_A; std::cout << "Derived destroyed" << std::endl; }
};

void ExecuteVirtualDestructors()
{
    Base* b = new Base(); // Base constructed
    delete b; // Base destroyed
    std::cout << "--------------------------" << std::endl;
    Derived* d = new Derived(); // Base constructed, Derived constructed
    delete d; // Derived destroyed, Base destroyed
    std::cout << "--------------------------" << std::endl;
    // Without virtual in Base destructor
    // Base* p = new Derived(); // Base constructed, Derived constructed
    // delete p; // Base destroyed

    // With virtual in Base destructor
    Base* p = new Derived(); // Base constructed, Derived constructed
    delete p; // Derived destroyed, Base destroyed
}
