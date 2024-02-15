#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

// Constructor
// Constructor – method of structure initialization;

struct Point
{

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point()
    {
        this->x = 0;
        this->y = 1;
    }

    int sum()
    {
        int result = this->x + this->y;
        return result;
    }

    void sum3();

    int x;
    int y;
};

void Point::sum3()
{
    this->x;
    this->y;
};

int main()
{
    Point p1;
    std::cout << p1.y << std::endl;
    Point p2(2, 3);
    std::cout << p2.y << std::endl;

    std::cout << p2.sum() << std::endl;
    return 0;
}

// список инициализации позволяет проинициализировать поля до входа в конструктор;
// struct Point
// {
//     Point(double x = 0, double y = 0) : x(0.), y(0.)
//     {
//     }
//     // поля могут иметь значения по умолчанию
//     // 1 с параметрами по умолчанию
//     // Point(int x = 0., int y = 0.) : x(x), y(y)
//     // {
//     // }
//     int x;
//     int y;
// };

// Point p1;
// Point p2(2);
// Point p3(3.0, 7.0);
// Инициализиции полей в списке инициализаций происходит в порядке объявления полей в структруе