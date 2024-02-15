#include <array>
#include <iostream>
#include <vector>

int main()
{
    // static arrays на стэке;
    //  В стиле C
    // int m[10] = {1, 2, 3, 4, 5};

    //<params>: = <type, quantity>
    std::array<int, 10> m = {1, 2, 3, 4, 5};
    // secure, friends with algorithms

    // в отличие от <vector> в compile-time известно кол-во байт;

    // for (int i = 0; i < m.size(); ++i)
    // {
    //     std::cout << m[i] << std::endl;
    // }

    // range based;
    // for (int el : m)
    // { // copy el on every iter
    //     // el -copy
    //     // &el -link
    //     std::cout << el << std::endl;
    // }

    // for (const int &el : m)
    // // cosnt by default
    // // m будет по ссылке
    // {
    //     m[0] = 0;
    //     std::cout << el << '\n';
    // };

    // vector is a dynamic array that выделяет memory on heap
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (const auto v : vec)
    {
        std::cout << v << " ";
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    return 0;
}