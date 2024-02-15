// Multiple inheritance – возможность наследовать
// сразу несколько классов
#include <vector>
#include <iostream>

typedef unsigned int unitid;

struct Unit
{
    Unit(unitid id, int hp) : id_(id), hp_(hp) {}
    virtual unitid id() const { return id_; }
    virtual int hp() const { return hp_; }

private:
    unitid id_;
    int hp_;
};

// для ромбовидного наследования;

struct Xrcher : virtual Unit
{
    Xrcher(unitid id, int hp) : Unit(id + 3, hp + 3){};
};

struct Elf : virtual Unit
{
    Elf(unitid id, int hp) : Unit(id + 1, hp + 1){};
};

struct ElfArcher : Xrcher, Elf
{
    ElfArcher(unitid id, int hp) : Xrcher(id, hp), Elf(id, hp) {}
    unitid id() const { return Elf::id(); }
    int hp() const { return Elf::hp(); }
    // segmentation fault
    // unitid id() const { return ElfArcher::id(); }
    // int hp() const { return ElfArcher::hp(); }
};

// virtual inheritance
// Elf Elf Unit
// Archer Archer Unit
// ElfArcher Elf Archer Unit
int main()
{
    // ElfArcher s(1, 1);
    // std::cout << s.hp() << std::endl;
    // std::cout << s.id() << std::endl;

    return 0;
}