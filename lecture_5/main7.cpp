#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Polymorphism
// Polymorphism – возможность единообразно обрабатывать разные типы данных;

// Перегрузка функций – выбор функции происходит в момент компиляции
// на основе типов аргументов (статический полиморфизм)

// Виртуальные методы
// Выбор метода происходит в момент выполнения на основе типа объекта
// у которого вызывается виртуальный метод, динамический полиморфизм;

// Таблица виртуальных методов;
// динамический полиморфизм реализуется при помощи таблиц виртуальных методов;
// Таблица заводится для каждого полиформного класса;

// Объекты полиформных классов содержат указатель на таблицу
// виртуальных методов соответствующего класса

// vptr name_ age_      // vptr name_ age_ uni_ // Person
// Person               // Student

// Вызов виртуального метода – это вызов метода по адресу из таблицы (в коде сохраняется номер метода в таблице)
// p->occupation(); // p->vptr[1]();

// в начале layout 4-8 bytes для вызова таблицы;
// overhead – в другой части памяти сходить и позвать метод;

struct Person
{
    virtual ~Person() = default;
    string name() const { return name_; }
    // pure virtual
    virtual string occupation() const = 0;

    string name_;
};

struct Student : Person
{
    string occupation() const { return "student"; }
    virtual int group() const { return group_; }

    int group_;
};

// virtual methods дописываютс в конец
// Построение иаблицы виртуальных методов;

struct Person
{
    virtual ~Person() {}
    virtual string occupation() = 0;
};

struct Teacher : Person
{
    string occupation() {}
    virtual string course() {}
};

struct Professor : Teacher
{
    string occupation() {}
    virtual string thesis() {}
};