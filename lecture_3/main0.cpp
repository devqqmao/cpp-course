#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

// Структуры – способы связать логически связанные данные
struct Point
{
    double x;
    double y;
};

// Struct or Class
// fields, operators

struct Segment
{
    Point p1;
    Point p2;
};

int main()
{
    double length(Segment s);

    bool intersects(Segment s1, Segment s2,
                    Point * p);

    return 0;
}

// access to fields

double length(Segment s)
{
    double dx = s.p1.x - s.p2.x;
    double dy = s.p1.y - s.p2.y;
    return sqrt(dx * dx + dy * dy);
}

double length(Segment *s)
{ // pointer
    // взятие адреса и разыменование с помощью *
    double dx = s->p1.x - s->p2.x;
    double dy = s->p1.y - s->p2.y;
    // стрелочка – комбинация звездочки и точки (разыменовали + перешли)
    return sqrt(dx * dx + dy * dy);
}
// no constructor-destructor in C

// для указателей на структуры используется ->
int main()
{
    Point p1 = {0.4, 1.4};
    Point p2 = {1.2, 6.3};
    Segment s = {p1, p2};
    return 0;
}

struct IntArray2D
{
    size_t a;
    size_t b;
    std::vector<int> data;
};

// IntArray2D a = {n, m, create_array2d(n, m)}

// POD type Plain Old Data <=> простые данные в стиле C

// все встроенные арифметические типы wchar_t, bool
// enum (перечисления)
// указатели
// POD-структуры (struct, class), union

// POD, if:
// no constructor / destructor
// ...

// Structure binding

struct Point
{
    int x;
    int y;
};

// int bar(int x)
// {
//     return 0;
// };
Point p = {1, 2};
auto [x, y] = p;
// bar(x); // equal to p.x

// std::pair

std::unordered_map<std::string, std::string> map;

auto [it, inserted] = map.emplace("key", "value");

int func()
{
    if (inserted)
    {
        int a;
        //
    }
    else
    {
        int b;
        //
    }
    return 0;
}

// Methods
// function declared inside of a struct

struct Segment
{
    Point p1;
    Point p2;
    double length()

    {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    Segment s = {{0.4, 1.4},
                 {1.2, 6.3}};

    std::cout << s.length() << std::endl;
    return 0;
}

// methods реализованы как функции с неявным параметром this,
// который указывает на текущий экземпляр структуры;

struct Point
{
    double x;
    double y;

    void shift(/* Point this this, */ double x, double y)
    {
        this->x += x; // this->x – ссылка на x
        this->y += y;
    }
};

struct Point
{
    double x;
    double y;
    void shift(double x, double y);
};

void Point::shift(double, double y) // calling class method
{
    this->x += x;
    this->y += y;
};
