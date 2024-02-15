#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool is_odd(int i)
{
    return i % 2 == 1;
}

int main()
{
    std::vector<int> m(10); // empty - zeroes

    // for (int i : m)
    // {
    //     std::cout << i << ' ';
    // }

    // std::cout << std::endl;

    std::iota(m.begin(), m.end(), 0);

    // option 1
    // for (auto it = m.begin(); it != m.end();) // m.end() ласт после последнего
    // {
    //     it = (*it % 2 == 0) ? m.erase(it) : std::next(it);
    //     // m.erase(it) – возвращает место, с которого можно итерироваться (на некст элемент)
    //     // берем по значению *it
    //     // delete all odd elements
    // }

    // option 2
    // m.erase(std::remove_if(m.begin(), m.end(), is_odd), m.end());
    // m.end() – result remove; выкинули
    // m.remove_if :: перемещает в конец элементы;

    // возвращает итератор на элемент после последнего;

    // option 3

    // std::erase_if(m, is_odd);

    for (int i : m)
    {
        std::cout << i << ' ';
    };

    return 0;
}