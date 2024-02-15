#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using std::cout;
using std::endl;

int **create_array2d(size_t a, size_t b)
{
    int **m = new int *[a];
    for (size_t i = 0; i != a; ++i)
        m[i] = new int[b];
    return m;
}

// в строках ссылки на столбцы
void free_array2d(int **m, size_t a, size_t b)
{
    for (size_t i = 0; i != a; ++i)
        delete[] m[i];
    delete[] m;
};

// Двумерные массивы: эффективная схема

// Рассмотрим эффективное создание массива 5x4

void fn()
{
    int **m = new int *[5];
    m[0] = new int[5 * 4];
    for (size_t i = 1; i != 5; ++i)
    {
        m[i] = m[i - 1] + 4; // арифметика указателей;
    }
    // расставляем указатели строк;
}

// Умные указатели
// 1. Идиома RAII (resources Acquisition Is Initialization):
// время жизни ресурса связано с временем жизни объекта;
// 1. Получение ресурса в конструкторе
// 2. Освобождение ресурса в деструкторе;

// Основные области использования RAII:

// 1. Для управления памятью,
// 2. Для открытия файлов или устройств,
// 3. Для критических секций при паралельном исполнении кода;

// Умные указатели – объекты, инкапсулирующие владение памятью. Синтаксически
// ведут себя так же, как и обычные указатели.

// Основные стратегии;

// boost
// scoped_ptr – время жизни объекта ограничено временем жизни умного указателя
// !shared_ptr – разделяемый объект, реализация с подсчетом ссылок.
// !weak_ptr - разделяемый объект, реализация с подсчетом ссылок, слабая ссылка (вместе с shared_ptr)
// !unique_ptr – эксклюзивное владение объектом с передачей владения при перемещении
// intrusive_ptr – раздляемый объект, реализация самим внутри объекта.
// linked_ptr – разделяемый объект, реализация списком указателей;

// unique_ptr:
// Определен в заголовочном файле <memory> (все).
// Для передачи и возврата указателей из функции.
// Владение эксклюзивно и передается только при перемещении

void foo(const std::unique_ptr<int> &ptr)
{
    std::cout << *ptr; // * возвращает значение
}

void bar(std::unique_ptr<int> &&ptr) // rvalue link
{
    std::cout << *ptr;
}

void baz(std::unique_ptr<int> ptr)
{
    std::cout << *ptr;
}

int main()
{
    // no copy, move only
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    auto &ptr_ref = ptr;

    // auto ptr_copy = ptr; // error
    foo(ptr);
    // bar(ptr); // error, тип не соответствует
    bar(std::move(ptr));
    // baz(ptr);
    baz(std::move(ptr));
}

// shared_ptr

// для разделяемых объектов
// ведется подсчет ссылок
// нельзя вернуть владение объектом
// ровно 1 раз вызван конструктор, ровно 1 раз вызван деструктор;

void foo(const std::shared_ptr<int> &ptr)
{
    std::cout << *ptr; // * возвращает значение
}

void bar(std::shared_ptr<int> &&ptr) // rvalue link
{
    std::cout << *ptr;
}

void baz(std::shared_ptr<int> ptr)
{
    std::cout << *ptr;
}

int main1()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    auto &ptr_ref = ptr; // no increment
    auto ptr_copy = ptr; // increment

    foo(ptr);
    // bar(ptr); //error;
    bar(std::move(ptr)); // no increment;
    baz(ptr);            // increment;
    baz(ptr);            // no increment;
}

int main2()
{
    // counter == 1
    std::shared_ptr<int> ptr = std::make_shared<int>(10);

    {
        // counter = 1
        auto ptr_copy = ptr;
        // counter == 2
    }

    {
        // counter = 1
        auto &ptr_ref = ptr;
        // counter = 1
    }

    {
        // counter = 1
        auto ptr_ref = std::move(ptr); // отдали владение -> зануление раньше
        // counter = 0
    }
}
// counter == 0 // clear memory

// weak_ptr

// для использования вместе с shared_ptr;
// слабая ссылка для исключения циклических зависимостей;
// не владеет объектом;

// void foo(std::weak_ptr<int> &ptr_weak)
// {
//     if (auto ptr_locked = ptr_weak.loc())
//     {
//         // shared here
//     }
// }

int main()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    foo(ptr);

    // make 1 strong link, 1 weak link => для разрешения зависимостей;
    // strong захватывает владение weak; weak <-> shared;
}

// smart pointers и const
// cosnt pointer
void fn1()
{

    const auto p1 = std::make_shared<int>(10);
    const auto p2 = std::make_shared<int>(10);

    // p1 = nullptr; // err
    // *p1 = 10;     // ok
    // p2 = nullptr; // ok
    // *p2 = 10;     // err
}

// smart pointers -> медленные
// для разделяемых владений –> shared ptr
// для уникальных –> unique
// intrusive_ptr для объектов, которые сами управлют своим временем жизни;