#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Interface
// Интерфейс – это абстрактный класс, у которого отсутствуют поля,
// а все методы являются чистыми виртуальными

struct IConvertibleToString
{
    virtual ~IConvertibleToString() {}
    virtual string toStirng() const = 0;
};

struct IClonable
{
    virtual ~IClonable() {}
    virtual IClonable *clone() const = 0;
};

struct Person : IClonable
{
    Person *clone() { return new Person(*this); }
};

// Множественное наследование

int main()
{
    return 0;
}
