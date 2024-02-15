#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

// const methods
// methods might be const
struct S
{
    // methods might be const
    // after arguments write const

    // cannot change fields
    // with pointer or link can be called only constant methods
    // Inside of constant methods only const methods can be called;

    const int &ref() const // f() `const` -> cannot change field names
    {
        return data_;
    }

private:
    int data_;
};
// 2 version of a single method
const int &S::ref() const { return data_; }

struct S
{
    const int &ref() const
    {
        return data_;
    }
    int &ref()
    {
        return data_;
    }

private:
    int data_;
};

// Synatexic and logical constant

// Syntaxic constant = const methods
// const methods cannot change fields

// logical const - нельзя менять те данные, которые определяют
// состояние объекта

int main()
{
    return 0;
}
