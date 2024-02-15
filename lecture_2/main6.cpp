#include <array>
#include <iostream>
#include <vector>

// работа с массивами;

void swap(std::array<int, 10> &arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void max_sort(std::array<int, 10> &arr)
{
    for (int i = 0; i < (static_cast<int>(arr.size()) - 1); ++i)
    {
        for (int j = (i + 1); j < static_cast<int>(arr.size()); ++j)
        {
            if (arr[i] > arr[j])
            {
                swap(arr, i, j);
            }
        }
    }
}

int main()
{

    std::array<int, 10> arr = {3, 2, 1, 5, 4, 3};
    std::vector<int> vec = {3, 2, 1, 5, 4, 3};

    // quadratic sort
    max_sort(arr);

    // print
    for (int &el : arr)
    {
        std::cout << el << std::endl;
    }

    return 0;
}