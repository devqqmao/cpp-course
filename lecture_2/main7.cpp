#include <array>
#include <iostream>
#include <vector>

// работа с массивами;

void swap(std::vector<int> &arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
};

void swap(std::array<int, 10> &arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
};

void print_vec(std::vector<int> &vec)
{
    for (int &el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void print_vec(std::array<int, 10> &vec)
{
    for (int &el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size() - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

void bubble_sort(std::array<int, 10> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size() - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

int main()
{
    std::array<int, 10> arr = {3, 2, 1};
    std::vector<int> vec = {4, 2, 1, 0, 2};
    bubble_sort(arr);
    print_vec(arr);
    print_vec(vec);
    return 0;
}