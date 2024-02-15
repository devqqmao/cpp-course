// Перегрузка функций
// В отличие от С в С++ можно определить несколько
// функций с одинаковым именем, но разными параметрами;

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

double square(double i) { return i * i; };
int square(int i) { return i * i; };

// the same name but different arguments
// в манглировании возвращаемое значение не фигурирует;

// перегружать можно только по аргументам;

// При вызове функции по имени будет произведен
// поиск наиболее подходящей функции:

int main()
{
    int a = square(4);        // square(int)
    double b = square(3.14);  // square(double)
    double c = square(2.71f); // square(double)
    return 0;
}

// methods overloading

struct Vector2D
{
    // Constructor
    // compiles just fine
    Vector2D(double x, double y) : x(x), y(y) {}

    //
    Vector2D mult(double d) const
    {
        return Vector2D(x * d, y * d);
    }

    // dot product
    // cannot modify fields or call non-const methods
    double mult(Vector2D const &p) const
    {
        return x * p.x + y * p.y;
    }

    double x, y;
};

struct File
{
    void write(char const *s);
};

int fn()
{
    Vector2D p(1, 2);
    Vector2D q = p.mult(10); // (10, 20)
    double r = p.mult(q);    // (50)
}

struct File
{
    void write(char const *s);
    //
};

struct FormattedFile : File
{
    void write(int i);
    void write(double d);
    using File::write;
};