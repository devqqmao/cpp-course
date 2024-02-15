#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool is_even(int el)
{
    return (el % 2 == 0);
}

int main()
{
    // подсчет элементов, удовл. предикату
    std::array<int, 10> m;
    std::iota(m.begin(), m.end(), 0);

    for (int el : m)
    {
        std::cout << el << ' ';
    }

    int counter = 0;
    for (int i : m)
    {
        if (is_even(i))
        {
            ++counter;
        }
    }

    std::cout << std::endl;
    std::cout << counter << std::endl;

    std::count_if(m.cbegin(), m.cend(), [](const auto &i)
                  { return i % 2 == 0; });

    std::cout << std::endl;
    std::cout << counter << std::endl;

    return 0;
}