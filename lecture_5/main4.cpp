#include <string>
#include <iostream>

struct File
{
    void write(char const *s);
};

struct FormattedFile : File
{
    void write(int i);
    void write(double d);
    using File::write;
};

int main()
{
    FormattedFile f;
    f.write(4);
    f.write("Hello");
};

// Перекрытие методов

// example

struct A
{
    void foo(int);
};

struct B : A
{
    void foo(long long);
    // using A::foo; // says method to use;
};

// int main()
// {
//     B b;
//     b.foo(1); // calls B::foo
// }

// compiler makes a priority list:
//

// меньше приведений -> более подходящая функция;

// Overloading rules
// Если есть точное совпадение, то используется оно;
// Если нет функции, которая могла бы подойти с учётом преобразований, выдается ошибка
// Есть функции, подходящие с учетом преобразований:
// Расширение типов: char, signed, char short -> int
// unsigned char, unsigned short -> int / unsigned
// int
// float -> double
// стандартные преобразования (числа, указатели)
// Пользовательские преобразования

// В случае нескольких параметров нужно,
// чтобы выбранная функция была строго лучше остальных

// NB: перегрузка выполняется на этапе компиляции;

// methods overloading
struct Person
{
    Person(std::string name) : name_(name) {}
    // virtual makes struct virtual
    virtual std::string name() const { return name_; }
    // ...
    std::string name_;
};

struct Professor : Person
{
    Professor(std::string name) : Person(name) {}
    // override checks if we truly override some method
    std::string name() const override
    {
        return "Prof. " + Person::name();
    }
    // ...
};

int main()
{
    Professor pr("Stroustrup");
    std::cout << pr.name() << std::endl;
    Person *p = &pr;
    // what does it mean
    std::cout << p->name() << std::endl;
};

// allocates space for stroutstroup
//

struct P
{
    std::string name()
    {
        return "Hello";
    };
};

// poly call: no prefix <-> professor prefix <-> mister
// приведем неявным образом, поэтому не увидим mister // prof, etc...

void print(P &p)
{
    std::cout << p.name();
};
