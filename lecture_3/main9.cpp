#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

// Copying and moving objects

// copying constructor and moving constructor;

// Language C++ позволяет определить поведение
// при копировании и перемещении объектов;
struct S
{
    // default constructor;
    S() = default;

    // Копирующий конструктор;
    // принимает константную ссылку на объект того же типа
    S(const S &) = default;

    // Перемещающий конструктор;
    // принимает value ссылку
    S(S &&) = default;

    // 1-ый копирует, из одного объекта делает копию другого;
    // перемещающий помещает один объект в другой

    // Оператор копирующего присваивания.

    // работает над уже существующим объектом
    S &operator=(const S &) = default;

    // Оператор перемещающего присваивания.
    S &operator=(S &&) = default;

private:
    int data;
};

struct S
{
    // vector as example
    S() = default;

    // копирующий конструктор
    S(const S &other) : data_(other.data) {} // copying

    // оператор копирующего присваивания
    S &operator=(const S &other)
    {
        data_ = other.data;
        return *this;
    }
    

private:
    std::vector<int> data = {1, 2, 3};
    std::vector<int> data_ = decltype(data_)(100500);
};

// int main()
// {
//     S s1;      // default
//     S s2(s1);  // copy
//     S s3 = s1; // copy
//     s2 = s1;   // operator=
//     return 0;
// }

// Copying objects

// Если не определить конструктор копирования, то он сгенерируется компилятором.
// Если не определ оператор присваивания, то он тоже сгенерируется копилятором.

struct V
{
    // Standard operator
    // V() = delete; // make object uncopiable;
    V() = default;

    V(const V &other) : data_(other.data){};

    V &operator=(const V &other)
    {
        data_ = other.data;
        return *this;
    }

private:
    std::vector<int> data = {1, 2, 3};
    std::vector<int> data_ = decltype(data_)(100500);
};

int main()
{
    return 0;
}