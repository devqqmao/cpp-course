#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// ООП – концепция, основанная на понятиях объектов и классов;
// инкапсуляция;

// Агрегирование vs наследование;
// Агрегирование – это включение обхекта одного класса в кач-ве поля в другой;
// Наследование устанавливает более сильные связи между классами, нежели агрегирование:
// Приведение между объектами;
// Доступ к protected членам;

// Если наследование можно легко заменить на агр. -> нужно делать;

// Примеры некорректного наследования
// Класс Circle унаследовать от класса Point
// LinearSystem от Matrix

// example
// cannot instantiate person

struct iPerson
{
    // all instances will have virtual destructor
    virtual ~iPerson(){};

    // must be realized: pure virtual
    virtual int foo() = 0;
};

int main()
{
    // pointer
    iPerson *p;
    return 0;
}

// Aggregation
struct S
{
};

struct S2
{
    S s;
};

struct S2 : S
{
    S2() : S() {}
};

// наследование
// дает приведение;
// доступ к public (private)

// наследование interface -> реализация;
// аггрегация other cases

// Принцип подстановки Барбары Лисков
// поведение наследуемых классов не должно противоречить
// поведению, заданному базовым классом

// Модификаторы при наследовании
struct A
{
};
struct B1 : public A
{
};
struct B1 : private A // спрятать интерфейс от внешнего
                      // пользователя, но самим иметь доступ
{
};                      //
struct B1 : protected A // внешний код взаимодействую по этому интерфейсу,
// но есть взаимодействие по другому, который нужен только внутри;
{
};

// для struct default public
// для объявленных class-private

// Важно: отношение наследование в ООП – public

// private - protected - наследований целесообразно, если необходимо не только
// агрегировать другой класс, но и переопределить его виртуальные методы ;

// множественные наследования;

// Переопределение private виртуальных методов;

struct NetworkDevice
{
    void send(void *data, size_t size)
    {
        log("start sending");
        send_impl(data, size);
        log("stop sending");
    }

private:
    virtual void send_impl(void *data, size_t size)
    {
        //
    }
};

struct Router : NetworkDevice
{
private:
    void send_impl(void *data, size_t size)
    {
        //
    }
};
