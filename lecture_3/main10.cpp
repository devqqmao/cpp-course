#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

struct S
{
    S() = default;
    S(S &&other) // std::move
        : data_(std::move(other.data_))
    { // init поле data другим конструктором;
    }
    // rvalue link -> special type //

    S &operator=(S &&other) // &&
    {
        data_ = std::move(other.data_); // std::move
        return *this;
    }

private:
    std::vector<int> data_ = decltype(data_)(100500);
};

void foo(const S &s)
{
}

int main()
{
    S s1;
    S s2(std::move(s1));
    S s3 = std::move(s2); // приводит 1 тип к другому;

    S s4;
    s4 = std::move(s3);

    foo(s1); // undefined move-after-use;
    // after foo object is alive but in an inspecified state;

    // copying -> записать всю дату в ячейки памяти; //

    // && move указатель на тот же адрес памяти и размер;
    return 0;
}