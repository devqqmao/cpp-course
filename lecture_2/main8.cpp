#include <array>
#include <iostream>
#include <vector>

void print_vec(std::vector<int> &vec)
{
    for (int &el : vec)
    {
        std::cout << el << std::endl;
    }
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4};
    print_vec(vec);
    return 0;
}