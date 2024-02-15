#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

struct Point
{
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    // x(x) y(y) – values to init with

    int x;
    int y;
};

struct Segment
{
    Segment() {}
    // explicit Segment(double length) : p2(length, 0) {}
    Segment(double length) : p2(length, 0) {}
    Point p1;
    Point p2;
};

// explicit запрещает неявное преобразование;
int main()
{
    Segment s1;      //
    Segment s2(10);  // явный вызов конструктора
    Segment s3 = 20; // error; explicit запрещает
    std::cout << s3.p2.x << std::endl;
    return 0;
}