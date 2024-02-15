#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::string s("hello");

    std::cout << s << std::endl;

    // opt 1
    for (char &el : s)
    {
        el = std::toupper(el);
    };

    std::cout << s << std::endl;

    // opt 2
    const auto f1 = [](char c)
    { return std::tolower(c); };
    std::transform(s.begin(), s.end(), s.begin(), f1); // результат пишет начиная с 3-го param s.begin()

    std::cout << s << std::endl;

    // opt 3 ??? wide_string
    std::for_each(s.begin(), s.end(), [](char c)
                  { return std::tolower(c); });
                  
    std::cout << s << std::endl;

    return 0;
}