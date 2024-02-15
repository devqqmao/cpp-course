// classes generation

template<typename TL>
struct inherit;


template<typename Types>
struct inherit<TypeList<Types>> : Types {};

struct D: inherit<Bases> {};

// SFINAE = substitution failure is not an error
template<class T>
void foo(typename T::value_type * v);

template<class T>
void foo(T t);

// полная специализация шаблонов: функции

template<class T>
void swap(T & a, T &b) {
    T  tmp(a);
    a = b;
    b = tmp;
};

class Database;

// template<>
// void swap<Database>(Database & a, Database &b) {
//     a.swap(b);
// };

template<class T>
void swap(Array<T> & a, Array<T> &b) {
    a.swap(b);
};