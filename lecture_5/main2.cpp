#include <string>
#include <iostream>

using std::string;

struct Person
{
    Person(string name, int age) : name_(name), age_(age) {}

private:
    string name_;
    int age_;
};

struct Student : Person
{
    Student(string name, int age, string uni) : Person(name, age), uni_(uni) {}

private:
    string uni_;
};

// Приведения
// Инкапсуляция – когда значения изменяются только через функции -> согласованны

int func()
{
    // Для производных классов следующие приведения
    // (неявные приведения);
    //

    Student s("Alex", 21, "Oxford");
    Person &l = s; // Student & -> Person &
    Person *r = &s;
    return 0;
}

// Поэтому объекты класса-наследника могут присваиваться
// объектам родительского класса:

int main()
{
    Student s("Alex", 21, "Oxford");
    Person p = s; // Person("Alex", 21)

    // При этом копируются только поля класса-родителя (срезка)
    // Т.е. в данном случае вызывается конструктор
    // Person(Person const &p), которые не знает про uni_
    //
    return 0;
}

// Модификатор доступа protected

// класс-наследник не имеет доступа к private-членам; родительского класса;

// для определения закрытых членов класса доступных наследникам используется модификатор protected

// протектед доступны только внутри реализации класса-наследника;

// struct Person
// {

// protected:
//     string name_;
//     int age_;
// };

// struct Student : Person
// {
//     // можно менять полня name_ and age_
// };

// наследники и извне не имеют доступа к private;
// наследники имеют, извне не имеют право доступа к protected