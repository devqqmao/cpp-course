#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

// 2 способа передачи массива;

bool contains(int *m, int size, int value)
{
    for (int i = 0; i != size; ++i)
    {
        if (m[i] == value)
        {
            return true;
        }
    }
    return false;
}

bool containts(int *p, int *q, int value)
{
    for (; p != q; ++p)
    {
        if (*p == value)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int m[10] = {1, 2, 3, 4, 5};
    auto length = std::size(m);
    contains(m, length, 4);
    return 0;
}

using std::cin;
using std::cout;
using std::endl;

bool contains(int *m, int length, int value)
{
    while ((length) > 0)
    {
        cout << (*m == value) << endl;
        if (*m == value)
        {
            return true;
        }
        ++m;
        --length;
    }
    return false;
}

int main()
{
    int m[5] = {1, 2, 3, 4, 5};
    auto length = std::size(m);
    std::cout << contains(m, length, 5);
    return 0;
}

int *max_element(int *p, int *q)
{
    int *pmax = p;
    for (; p != q; ++p)
    {
        if (*p > *pmax)
        {
            pmax = p;
        }
    }
    return pmax;
}

int main()
{
    int m[10] = {1, 2, 3, 4, 5};
    int *pmax = max_element(m, m + 10);
    cout << pmax;
    return 0;
}

//  Возврат значения через указатель

bool max_element(int *p, int *q, int *res)
{
    if (p == q)
    {
        return false;
    }
    *res = *p;
    for (; p != q; ++p)
    {
        if (*p > *res)
        {
            *res = *p;
        }
    }
    return true;
}

int main()
{
    int m[10] = {4, 3, 2, 1};
    int max = 0;
    if (max_element(m, m + 10, &max))
    {
        cout << "Maximum = " << max << endl;
    }

    return 0;
}

// указатель на указатель
bool max_element(int *p, int *q, int **res)
{
    if (p == q)
        return false;
    *res = p;
    for (; p != q; ++p)
        if (*p > **res)
            *res = p;
    return true;
}

int main()
{
    int m[10] = {1, 2, 3, 4};
    int *pmax = 0;
    if (max_element(m, m + 10, &pmax))
        cout << *pmax << endl;
    return 0;
}
