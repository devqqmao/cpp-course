// Multiple inheritance – возможность наследовать
// сразу несколько классов
#include <vector>
#include <iostream>

// operator overloading

// unary: prefix, postfix
// binary

// byte:
// unary:
// ~
// binary:
// & | ^ &=
// ..

// присваивание;
// . :: не перегружается;
// можно переопределить

struct Vector
{
    Vector() = default;
    Vector(int x, int y) : x_(x), y_(y){};
    int x_;
    int y_;
};
Vector operator-(Vector const &v)
{
    return Vector(-v.x_, -v.y_);
};

Vector operator+(Vector const &v,
                 Vector const &w)
{
    return Vector(v.x_ + w.x_, v.y_ + w.y_);
};

Vector operator*(Vector const &v,
                 double d)
{
    return Vector(v.x_ * d, v.y_ * d);
};

Vector operator*(double d,
                 Vector const &v)
{
    return v * d;
};

// Перегрузка опреаторов внутри классов

// struct Vector
// {
//     Vector operator-() const { return Vector(-x_, -y_); }
// };

int main()
{
    Vector v(1, 1);
    Vector v_1 = -v;
    std::cout << v_1.x_ << ' ' << v_1.y_ << std::endl;
    Vector v_2 = v + v_1;
    std::cout << v_2.x_ << ' ' << v_2.y_ << std::endl;

    return 0;
}