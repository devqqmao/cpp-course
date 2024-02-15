#include <array>
#include <iostream>
#include <vector>
#include <algorithm>

// работа с массивами;

void swap(std::vector<int> &arr, int i, int j)
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

int main()
{
    std::vector<int> vec = {4, 2, 1, 0, 2};

    print_vec(vec);
    // bubble_sort(vec);

    std::sort(vec.begin(), vec.end());
    std::swap(vec[0], vec[1]); // vec[0]
    print_vec(vec);

    // begin() function is used to return an iterator pointing to the first element of the vector container.
    // begin() function returns a bidirectional iterator to the first element of the container.

    // end() function is used to return an iterator pointing next to last element of the vector container.
    // end() function returns a bidirectional iterator.

    return 0;
}