#include <iostream>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <typeinfo>
#define max3(a, b)  (((a) > (b)) ? (a) : (b));
#define min(a, b) (((a) < (b)) ? (a) : (b));
// #define max4(x, y)  x > y ? × : y
#ifdef DEBUG
    // extra checks
#endif

using namespace std;

int mainTypes()
{
    unsigned long i = 432;
    cout << std::numeric_limits<std::uint32_t>::max() << "\n";
    cout << typeid(i).name();
    return 0;
}

int mainVariables()
{

    // variables

    int i = 10;
    short j = 10;
    bool b = false;
    unsigned long l = 123123;
    double x = 10.5, y = 3.1415;
    float z;

    // нужно инитить переменные (declaration only doesn't work)
    
    // операции
    //  == присваивание
    // arithmetical
    //  binary + - * / %

    int k = i + i;
    short jj = j * 2;
    double q = x / y;
    unsigned long ll = l % 2;

    // unary ++ --
    // logical && ||
    // unary !

    // comparisons
    // > < >= <= == != <>

    // C-style приведение типов: (type)

    // += -= *= /= %=

    // Operations
    int ii = 10;
    ii = (20 * 3) % 7;

    return 0;
}

int increments()
{
    int i = 10;

    cout << i << "i \n";
    int j = i++; // post increment; assigns to j and then increments
    int l = ++i; // pre increment; increments and then assigns

    cout << i << "i \n";
    cout << j << "j \n";
    cout << l << "l \n";

    bool res = true or false;

    cout << res << "\n";

    int k = 10;
    int q = 20;

    // auto p = k <=> q; // returns ordering object i, l – ints;
    // p = -1 if k < q; p=0 if k = q p = 1 k > 1

    auto u = 0; // auto

    return 0;
}

int instructions()
{ // unspecified behavior
    int i = 10;
    i = (i += 5) + (i * 4); // в рамках одной строчки компилятор сам выбирает порядок действий
    // здесь он сначала прибавил, потом умножил на 4, потом сложил => 75
    return i;
}

void context()
{
    int k = 10;
    int i = 20;
    {
        // int k = 5 * i;
        // i = (k += 5) + 5;
    }
    cout << k << "\n"; // вновь объявленная k не видна за пределами блока
    cout << i << "\n"; // изменения с k влияют на i, изменения сделанные с i видны.
}

void undefinedBehavior()
{
    int i = std::numeric_limits<int>::max() + 1; // UB
    int j = std::numeric_limits<int>::max();     // UB
    cout << i << "\n";
    cout << j << "\n";
}

// unspecifiedBehaviorAccordingToCompiler

void foo(int a, int b, int c)
{
    std::cout << a << b << c; // prints a, b, c
}

void func()
{
    int roots = -1;

    int a = 2;
    int b = 10;
    int c = 3;
    int d = b * b - 4 * a * c;

    if (d > 0)
    {
        roots = 2;
    }
    else if (d == 0)
    {
        roots = 1;
    }
    else
    {
        roots = 0;
    }

    // ternary operator

    roots = 0;

    if (d >= 0)
    {
        roots = (d > 0) ? 2 : 1;
    }
}

void loopsFunc()
{
    // while loop
    int squares = 0;
    int k = 0;

    // condition to check
    while (k < 10)
    {
        squares += k * k;
        k = k + 1;
    }
    cout << squares << "\n";

    squares = 0;

    // for loop

    // init var, stop condition, action for each step
    for (int k = 0; k < 10; k = k + 1)
    {
        squares += k * k;
    }

    cout << squares;

    // break / continue operator
}

// variables are copied

// it's a copy of external var; value is passed
void strange(double x, double y)
{
    x = y;
}

double square(double x)
{
    return x * x;
}

int max1(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max2(int a, int b)
{   
    return (a > b) ? a : b;
}

void io() {
    int a = 0;
    int b = 0;

    cin >> a >> b;

    cout << "(a % b) = " << (a % b) << endl;
}


int main()
{

    // redeclaration is prohibited, but redefinition is ok
    // int i = 10;
    // cout << i << '\n';
    // i = 20;

    // int i = 0;
    // foo(++i, i++, i); // multiple unsequenced modifications to 'i' [-Wunsequenced]
    // ++i change -> return
    // i++ return -> change

    // loopsFunc();
    // strange(2., 3.);
    // cout << square(3.);

    // cout << max1(2, 4);
    // cout << max2(2, 4);
    // std::cout << max3(2, 4);
    // std::cout << min(2, 3);

    io();
    return 0;
}