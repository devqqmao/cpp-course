#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

// Syntaxic and logical constant

// Syntaxic constant = const methods
// const methods cannot change fields

// logical const - нельзя менять те данные, которые определяют
// состояние объекта;

// mutable => change fields inside constant methods;
struct S
{
    void foo() const
    {
        data_ = 10; // now ok
    }

private:
    // mutable позволяет изменять поля, которые можно имзенять
    // внутри константных методов
    mutable int data_; // for caching
};

int main()
{
    return 0;
}

// Синтаксическая константность – константные методы не могуть менять поля
// (обеспечивается компилятором)
// Логическая константность – нельзя менять те данные,
// которые определяют состояние объекта
struct S
{
    void foo() const
    {
        // data_ = 10; // error
    }

private:
    int data_; // data => cache;
};
