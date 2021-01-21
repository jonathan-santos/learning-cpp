#include <iostream>

void CStyleCast()
{
    int a = 5;
    double b = a;
    double c = (int)a;
}

void CPPStyleCast()
{
    int a = 5;
    double b = static_cast<int>(a);
}

class EntityCast
{
public:
    virtual void Print() { }
};

class PlayerCast : public EntityCast { };
class EnemyCast : public EntityCast { };


void CPPDynamicCast()
{
    PlayerCast* p = new PlayerCast();
    EntityCast* actuallyPlayer = p;
    EntityCast* actuallyEnemy = new EnemyCast();

    PlayerCast* p1 = dynamic_cast<PlayerCast*>(actuallyPlayer);
    std::cout << "p1: " << p1 << std::endl; // will return a valid pointer address

    PlayerCast* p2 = dynamic_cast<PlayerCast*>(actuallyEnemy);
    std::cout << "p2: " << p2 << std::endl; // will return a empty (NULL) pointer address (0), because the dynamic cast failed
}

void ExecuteCasting()
{
    CStyleCast();
    CPPStyleCast();
    CPPDynamicCast();
}
