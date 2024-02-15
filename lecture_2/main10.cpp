#include <array>
#include <iostream>
#include <vector>
#include <algorithm>

void print_vec(std::vector<int> &v)
{
    std::cout << "!" << std::endl;
    for (int &el : v)
    {
        std::cout << el << " ";
    }
}

int main()
{
    std::vector<int> m = {1, 2, 3, 4};
    // std::vector<int> m_copy;

    // for (int &el : m)
    // {
    //     m_copy.push_back(el);
    // }

    // print_vec(m_copy);
    // m_copy.clear();
    // print_vec(m_copy);

    // std::copy(m.cbegin(), m.cend(), m_copy.end());
    // print_vec(m_copy);
    // m_copy.clear();

    // Returns a const_iterator pointing to the first element in the container.
    // A const_iterator is an iterator that points to const content.
    // This iterator can be increased and decreased (unless it is itself also const),
    // just like the iterator returned by vector::begin,
    // but it cannot be used to modify the contents it points to, even if the vector object is not itself const.

    std::vector<int> m_copy(m.cbegin(), m.cend()); // constructor
    print_vec(m_copy);

    return 0;
}