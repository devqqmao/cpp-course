#include <string>
#include <iostream>

using std::string;

// Наследование, полиморфизм, инкапсуляция
// Наследование – механизм, позволяющий создавать
// производные классы, расширяя уже существующие;

// расширить содержимое

struct Person
{
    string name() const { return name_; }
    int age() const { return age_; }

private:
    string name_;
    int age_;
};

// можно писать квалификаторы, множественное наследование;
struct Student : Person
{
    string university() const { return uni_; }

private:
    string uni_;
};

// Класс-наследник;
// У объектов класса-наследника можно
// вызывать публичные методы родительского класса.

int func()
{
    Student s;
    std::cout << s.name() << std::endl;
    std::cout << s.age() << std::endl;
    std::cout << s.university() << std::endl;
    return 0;
}

// Внутри объекта класса-наследника хранится экзмепляр
// родительского класса;

int main()
{
    func();
    return 0;
}

// создание-удаление объекта класса-наследника

// struct Person
// {
//     Person(string name, int age) : name_(name), age_(age) {}

// private:
//     string name_;
//     int age_;
// };

// struct Student : Person
// {
//     Student(string name, int age, string uni) : Person(name, age), uni_(uni) {}

// private:
//     string uni_;
// };

// инитятся поля родительского класса, потом наследника
// деструктор в обратном порядке
