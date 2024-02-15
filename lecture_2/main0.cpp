#include <iostream>

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
    //swap changes only local copy
}

void swap2(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}


int main()
{
    int k = 10, m = 20;
    swap(k, m);
    std:: cout << k << ' ' << m << std::endl; // 10 20
    swap2(k, m);
    std:: cout << k << ' ' << m << std::endl; // 10 20
    std::cout << "Hello world";
    return 0;
}