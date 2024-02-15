#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// final запретить дальнейшее наследование или
// переопределение методов

struct A final
{
};

// cannot instantiate from final

struct B : A
{
}; // error

struct A
{
    virtual void foo(){};
};
struct B : A
{
    void foo() final{};
};
struct C : B
{
    void foo() {};
}; // error

// override позволяет провести проверки времени компиляции

struct A
{
    virtual void foo(int){};
}; // int -> double
struct B : A
{
    void foo(double) override{};
}; // -> получили бы 2 перекрывающих метода;


