#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
int main()
{
    int m[10] = {1, 2, 3, 4, 5};
    int *p = &m[0]; // адрес начала массива: ссылка, по которой можно менять
    int *q = &m[9]; // адрес последнего элемента
    int var = m[3]; // адрес последнего элемента
    
    std::cout << var << std::endl;
    std::cout << *p << ' ' << q << std::endl;
    return 0;
}

int **create_array2d(size_t a, size_t b)
{
    int **m = new int *[a];
    for (size_t i = 0; i != a; ++i)
        m[i] = new int[b];
    return m;
}

// в строках ссылки на столбцы
void free_array2d(int **m, size_t a, size_t b)
{
    for (size_t i = 0; i != a; ++i)
        delete[] m[i];
    delete[] m;
};