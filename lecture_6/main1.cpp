// Multiple inheritance – возможность наследовать
// сразу несколько классов
#include <vector>
#include <iostream>

typedef unsigned int unitid;

struct Unit
{
    Unit() = default;
    Unit(unitid id, int health);
    unitid id;
    int health;
};

struct Elf : virtual Unit
{
    explicit Elf(unitid id) : Unit(id, 100){};
};

struct Archer : virtual Unit
{
    explicit Archer(unitid id) : Unit(id, 120){};
};

struct ElfArcher : Elf, Archer
{
    explicit ElfArcher(unitid id) : Unit(id, 150),
                                    Elf(id),
                                    Archer(id){};
    // prohibits implicit convertions
};

// first rule of virtual inheritance -> don't use it
// не использовать множественное наследование
// использовать интерфейсы

int main()
{
    // unitid id = e->__getUnitPtr__()->id;
    // служебный виртуальный метод;
    return 0;
}