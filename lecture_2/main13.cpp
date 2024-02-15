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
    std::string s_copy;
    std::string s("hello");

    for (const char &c : s)
    {
        if (c != 'l')
        {
            s_copy += c;
        }
    }

    std::cout << s_copy << std::endl;

    s.erase(1, 2); // removes [1, 2)
    // by pointer p
    // by post, len


    std::cout << s << std::endl;

    return 0;
}