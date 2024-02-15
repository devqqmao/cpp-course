#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Чисто виртуальные (абстрактные) методы

struct Person
{
    virtual std::string occupation() const = 0;
    // virtual = 0; -> have to be redefined
};

struct Student : Person
{
    std::string occupation() const { return "student"; }
};

struct Professor : Person
{
    std::string occupation() const { return "professor"; }
    // override??
};

int main()
{
    Person *p = next_person();
    std::cout << p->occupation();
    return 0;
}

// Виртуальный деструктор

struct Person
{
    Person(string name, int age) : name(name), age(age) {}
    // if we forgot to implement virtual destructor -> data leakage;
    virtual std::string occupation() { return "US"; };
    virtual ~Person() = default;
    // все деструкторы классов наследников
    // ...

private:
    string name;
    int age;
};

struct Student : Person
{
    Student(string name, int age, string occup) : Person(name, age), uni_(occup){};

private:
    string uni_;
};

int main()
{
    Person *p = new Student("Alex", 21, "Oxford");
    // почистим все без переопределения
    // ...
    delete p;
    // базовы класс -> почистим только базовый класс$
}
