// Multiple inheritance – возможность наследовать
// сразу несколько классов
#include <vector>
#include <iostream>
#include <algorithm>

struct Vector
{
    Vector(int x, int y) : x(x), y(y){};

    // передали -
    Vector operator-() const { return Vector(-x, -y); }
    Vector operator-(Vector const &p) const
    {
        return Vector(x - p.x, y - p.y);
    };

    Vector &operator*=(double d)
    {
        x *= d;
        y *= d;
        return *this; // return a link to itself
    };

    double operator[](size_t i) const
    {
        return (i == 0) ? x : y;
    };

    void operator()(double a, double b)
    { /**/
    }

    // bool operator()(double d) const {}
    // void operator()(double a, double b) {}

    double x, y;
};

// перегрузка инкремента / декремента

struct BigNum
{
    BigNum(int value) : value(value){};

    BigNum &operator++()
    { // prefix
        // increment
        return *this;
    };

    BigNum operator++(int)
    {                      // postfix
        BigNum tmp(*this); // save copy (приведение)
        ++(*this);
        return tmp;
    };

    int value;
};

// перегрузка операторов ввода // вывода

#include <iostream>

std::istream &operator>>(std::istream &is, Vector &p)
{
    is >> p.x >> p.y;
    return is;
};

std::ostream &operator<<(std::ostream &os, Vector const &p)
{
    os << p.x << ' ' << p.y;
    return os;
}

// Умный указатель;
// RAII

struct Data
{
    int id;
};

struct SmartPtr
{
    Data &operator*() const { return *data_; }
    Data *operator->() const { return data_; }
    Data *get() const { return data_; }

private:
    Data *data_; // т.к. не меняем значение
};

bool operator==(SmartPtr const &p1,
                SmartPtr const &p2)
{
    return p1.get() == p2.get();
}

// указатели на функции
// кроме указателей на значения в С++ присутствуют три оосбенных типов указателей;
// указатели на функции (из С);
// Указатели на методы;
// Указатели на поля классов;

// параметризация алгоритмов
// callback
// шаблон Listener
// создание очередей событий / заданий;

// указатели на функции: параметризация алгоритмов

bool less(double a, double b) { return a < b; }

void sort(double *p, double *q,
          bool (*cmp)(double, double))
{
    for (double *m = p; m != q; ++m)
        for (double *r = m; r + 1 != q; ++r)
            if (cmp(*(r + 1), *r))
                std::swap(*r, *(r + 1));
};

// о полезности using

// char *(*func(int, int))(int, int, int *, float); // returns func

// std::function может хранить любой вызываем,
// возвращающий себя;
using SomeFunction = std::function<char *(int, int, int *, float)>;
SomeFunction func(int, int);

// указатели на методы, чтобы передавать в качестве обработчка;

struct Person
{
    std::string name() const;
    std::string surname() const;
};

using MPTR = std::string (Person::*)() const;

void print(Person const &p)
{
    static MPTR im[2] = {
        &Person::name,
        &Person::surname};
    for (size_t i = 0; i != 3; ++i)
        std::cout << (p.*im[i])();
};

// Указатели на члены данных;

struct Person1
{
    std::string name;
    std::string surname;
};

using DPTR = std::string Person1::*;

void print(Person1 const &p)
{
    static DPTR im[2] = {
        &Person1::name,
        &Person1::surname};

    for (size_t i = 0; i != 3; ++i)
        std::cout << (p.*im[i]);
};

// Syntax summary;
using std::string;

struct Student
{
    string name() const { return name_; }
    string name_;
};

int main()
{
    string (Student::*mptr)() const = &Student::name;
    string Student::*dptr = &Student::name_;
    Student s;
    Student *p = &s;
    (s.*mptr)() == (p->*mptr)();
    (s.*dptr) == (p->*dptr);
};

struct Foo
{
    int i;
    void f();
};

int main()
{
    Foo foo;
    Foo *fooPtr = &foo;
    int Foo::*iPtr = &Foo::i;
    void (Foo::*memFuncPtr)() = &Foo::f;

    foo.*iPtr = 0;
    fooPtr->*iPtr = 0;
    (foo.*memFuncPtr)();
    (fooPtr->*memFuncPtr)();
}

// the same
// std::invoke

int main() {
    Foo foo;
    Foo* fooPtr = &foo;
    auto iPtr = &Foo::i;
    auto memFuncPtr = &Foo::f;

    std::invoke(iPtr, foo) = 0;
    std::invoke(iPtr, fooPtr) = 0;

    std::invoke(memFuncPtr, foo);
    std::invoke(memFuncPtr, fooPtr);
}

// int main()
// {
//     double m[100];
//     std::vector<int> m = {1, 2, 3};
//     sort(m, m + 3, &less);
//     return 0;
// }