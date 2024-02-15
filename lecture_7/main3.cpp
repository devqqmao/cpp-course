// metaprogramming

// Создание программ, которые порождаю другие программы;

// Шаблоны С++ можно рассматривать как функциональный язык для метапрогр;

// Метапрограммы С++ позволяют оперировать типами, шаблонами, compile-time значениями;

// MPL, Hana

// метафункции

// метафункция – это шаблонный класс, который определяет имя типа type или целочисленную
// константу value.

// аргументы метафункции – это аргументы шаблона.
// возвращаемое значение – это type or value

// Метафункции

// передается все то, что известно на момент компиляции
template <typename T>
struct add_pointer
{
    using type = T *;
};
// returns T *

// берет type T и возвращает T *

template <int N>
struct square
{
    static int const value = N * N;
};
// returns

// _t -> types 
// _v -> values

// typedef <-> using

template <typename T>
using add_pointer_t = add_pointer<T>::type;

template <int N>
constexpr auto square_v = square<N>::value;

template <typename T>
int foo(T *value)
{
    constexpr auto is_pointer = std::is_same_v<
        int *,
        add_pointer_t<T>>;
    // constexprt известно на этапе компиляции
    if constexpr (is_pointer)
    {
        return *value;
    }
    else
    {
        return square_v<10>;
    }
}

// специализация шаблонов
template <int N>
struct Fact
{
    static int const value = N * Fact<N - 1>::value;
};

template <>
struct Fact<0>
{
    static int const value = 1;
};

#include <iostream>
int main()
{
    std::cout << Fact<10>::value << std::endl;
}

int main()
{
    int a = 1;
    float b = 1.f;
    foo(&a);
    foo(&b);
    return 0;
};

// constexpr -> на этапе компиляции;

constexpr int fact(int N) {
    if (N == 1) {return 1;}
    return N * fact(N - 1);
}

int main()
{
    constexpr auto a = fact(10);
    std::cout << a << std::endl;
}

// const exprt => справа только constexpr
//              <- справа constexpr

// определение списка
template <typename Types>
struct TypeList;

template <typename H, typename T>
struct TypeList<H, T>
{
    using Head = H;
    using Tail = TypeList<T>;
};

// специализация списка;
template<>
struct TypeList<T> {};

// вычисление длины списка
template<typename TL>
struct Length {
    static int const value = 1 + Length<typename TL::Tail>::value;
};

template<>
struct Length<TypeList<>> {
    static int const value = 0;
};

int main() {
    using TL = TypeList<double, float, int, char>;
    std::cout << Length<TL>::value << std::endl;
}