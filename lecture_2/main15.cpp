#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

int main()
{
    std::vector<int> m(10);
    std::iota(m.begin(), m.end(), 0);

    const auto even = [](const int i)
    { return i % 2 == 0; };

    // unavailable for views
    // for (auto &v : m | std::views::filter(even))
    // {
    //     std::cout << v << ' ';
    // }

    // opt2

    // const auto square = [](int i)
    // { return i * i; };
    // for (auto &i : m | std::views::filter(even) | std::views::transform(square))
    // {
    //     std::cout << i << std::endl;
    // }

    {
        {
            {
                int a = 0;
            } // вызывается деструктор
        }
    }

    // string::view – ссылка на начало / конец, которая не владеет тем, на что указывает

    //C-style
    // const auto even = [](int i)
    // { return i % 2 == 0; };
    // const auto counter = std::ranges::count_if(m, even);

    // std::ranges::copy(
    //     std::views::filter(m, even),
    //     std::back_inserter(m_copy));

    return 0;
}