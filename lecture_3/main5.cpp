#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

// при создании конструктор
// при разрушении – деструктор;

struct Point
{
    Point() // constructor
    {
        std::cout << "A" << std::endl;
    }
    ~Point() // destructor
    {        // no params
        std::cout << "A" << std::endl;
    }
};

void foo()
{
    std::cout << "in" << std::endl;
    Point p;
    std::cout << "out" << std::endl;
}
int main()
{
    foo(); // const - dest
    return 0;
}

// Life time interval between destr call and constr call

// Деструкторы вызываются в обратном порядке (по отношению к порядку вызова конструкторов)

void foo()
{
    Point p1;
    Point p2;

    // decrease lifetime
    {
        Point p3;
    }
}

// Objects and classes

// Structure with methods, constr, destr – class;
// Exemplar = object;

// Access modifications

// ограничивают доступы к методам и полям класса;

struct Point
{
private:
    double x;
    double y_;

public:
    explicit Point(double x = 0, double y = 0) : x(x), y_(y) {}

    double x() { return x; }
    void set_x(double x_new) { x = x_new; }
};

class Point
{
    double x_;
    double y;

public:
    explicit Point(double x = 0, double y = 0) : x_(x), y(y) {}
    int x() { return x_; }
    void set_x(int x_new) { x_ = x_new; }
};

// in structs the default accessibility is public,
// whereas in classes the default is private

// class invariants
// public interface helps to

// Выделение публичного интерфейса позволяет
// поддерживать инварианты класса;
// (сохранять данные объекта в согласованном состоянии);

struct IntArray
{
    size_t size_;
    int *data_; // massive size of size_
};

// to keep class invariant;
// all fields must be closed;
// public methods must keep class invariants;