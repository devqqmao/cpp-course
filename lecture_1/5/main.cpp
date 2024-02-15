#include <iostream>

int foo(int a, int b, int c)
{
    double d = a * b * 2.17;
    int h = c ? d : d / 2;
    return h;
}

int main()
{
    int x = 1;
    int y = 2;
    x = foo(x, y, false);
    std::cout << x;
    return 0;
}