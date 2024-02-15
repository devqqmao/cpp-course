#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

struct Point
{
    Point(double x = 0, double y = 0) : x(0), y(0) {}

    int x;
    int y;
};

struct Segment
{
    // генерация конструктора по умолчанию генератором;
    Segment(Point p1, Point p2)
        : p1(p1), p2(p2) {}

    Point p1;
    Point p2;
};

// удаление конструктора по умолчанию$
struct Segment
{
    Segment() = delete;
    Point p1;
    Point p2;
};

struct Point
{
    explicit Point(double x = 0, double y = 0) : x(x), y(y) {}
    double x;
    double y;
};

int main()
{
    Point p1(); // definition var;
    Point p2(); // functions declaration
    double k = 5.1;
    Point p3(int(k)); // declar
    Point p4((int)k); // def var
    return 0;
}
