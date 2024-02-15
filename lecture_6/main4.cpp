// Multiple inheritance – возможность наследовать
// сразу несколько классов
#include <vector>
#include <iostream>
#include <algorithm>
#include <compare>
#include <set>

template <typename ItemType>
struct List
{
    List(ItemType *head,
         ItemType *ItemType::*nextMemPointer)
        : m_head(head), m_nextMemPointer(nextMemPointer){};

    void addHead(ItemType *item)
    {
        (item->*m_nextMemPointer) = m_head;
        m_head = item;
    }

private:
    ItemType *m_head;
    ItemType *ItemType::*m_nextMemPointer;
};

// оператор приведения

struct String
{
    operator bool() const
    {
        return size_ != 0;
    }

    operator char const *() const
    {
        if (*this)
            return data_;
        return "";
    }

private:
    char *data_;
    size_t size_;
};

// операторы с особым порядком вычисления

struct P
{
    int data = 0;
};

// no lazy semantics
// Tribool operator&&(Tribool const &b1,
//            Tribool const &b2);

// переопределение арифметических операторов;

struct String
{
    String(char const *cstr)
    { /*...*/
    }
    String &operator+=(String const &s)
    {
        return *this;
    }
    // String operator+(String const &s2) const {...}
};

String operator+(String s1, String const &s2)
{
    return s1 += s2;
};

// правильное переопределение
// переопределять смежное

bool operator==(String const &a, String const &b)
{
    return true;
};
bool operator!=(String const &a, String const &b)
{
    return !(a == b);
};

struct Record
{
    std::string name;
    unsigned int floor;
    double weight;
    auto operator<=>(const Record &) const = default;
};

struct Base
{
    std::string zip;
    auto operator<=>(const Base &) const = default;
};

struct TotallyOrdered : Base
{
    std::string tax_id;
    std::string first_name;
    std::string second_name;

    // public:
    //     std::strong_ordering TotallyOrdered::operator<=>(const TotallyOrdered &that) const
    //     {
    //         if (auto cmp = (Base &)(*this) <=> (Base &)that; cmp != 0)
    //             return cmp;
    //         if (auto cmp = last_name <=> that.last_name; cmp != 0)
    //             return cmp;
    //         if (auto cmp = first_name <=> that.first_name; cmp != 0)
    //             return cmp;
    //         return tax_id <=> that.tax_id;
    //     }
    //     // custom operator<=>
};

// стандартная семантика операторов.
// void operator+(A const &a, A const& b) {};

// приоритет операторов;

int main()
{
    String s1("world");
    String s2 = "Hello" + s1;
    return 0;
}