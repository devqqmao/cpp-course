#include <array>
#include <iostream>
#include <vector>

int main()
{
    auto op = [](int x, int y)
    { return x / y; };

    auto op1 = [](int x, int y) -> float
    { return x / y; };
    // std::cout << op1(4, 2) << std::endl;

    int total = 0;

    // caputring by link
    auto f1 = [&total](int x)
    { total += x; };

    // caputring by value total = 0
    // auto f2 = [total](int x) //
    // { return x - total; };

    // все по ссылке; все, что есть
    // в текущей области видимости;
    auto f3 = [&](int x)
    { return total; };

    // everything by value
    auto f4 = [=](int x)
    { return total; };

    f1(1);

    std::cout << total << " first" << std::endl;
    // caputring by value; takes
    // value by the time it was defined; total = 1;
    auto f2 = [total](int x)
    { return x - total; };
    std::cout << f2(2) << " second" << std::endl;
    std::cout << total << " third" << std::endl;

    return 0;
}