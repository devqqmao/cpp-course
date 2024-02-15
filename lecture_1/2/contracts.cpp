// contracts

#include <iostream>

using namespace std;

int main() {
    int a = 0;
    std::cout << "Enter a == 2: " << endl;

    std:cin >> a;

    // во время исполнения
    assert(a == 2);

    // static expressions must be calculated during compiling phase
    // static_assert((a == 2), "a should be 2");

    return 0;
}