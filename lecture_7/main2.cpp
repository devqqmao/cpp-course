// доступна только пределах функции
// работает только на этапе линковки;

static void test()
{
    //...
}

// нас интересуют 2 типа линковки: internal и external;
// internal in .cpp
// external static global vars, static funcs, in безымянном namespace -> internal
int main()
{
    return 0;
}

// static field -> global varis inside of a class
// non instance required for access

// статические методы – функции внутри класса, имеющие доступ к закрытым полям и методам

// inline -> советует компилятору встроить данную функцию

inline double square(double x) { return x * x; }

// В месте вызова inline-функции должно быть известно ее определение;
// inline functions можно определять в .h
// все функции, определенные внутри класса, являются inline
// из всех версий inline выбирается одна
//

// правило одного определения

// ODR
// в пределах любой единицы трансляции сущности (.cpp, func) не могут
// иметь более одного определения

// глоб. переменные и не-inline функции не могут иметь > одного определения

// classes and inline functions могут определяться в более чем одной единице трансляции, но определения обязаны совпадать;

// class Singleton

struct Data
{
};

struct Singleton
{
    static Singleton &instance()
    {
        static Singleton s;
        return s;
    }
    Data &data() { return data_; }

private:
    Singleton() = default;
    Singleton(Singleton const &) = delete;
    Singleton &operator=(Singleton const &) = delete;
    Data data_;
};

int main()
{
    // первое обращение
    // is inited
    Singleton &s = Singleton::instance();
    Data d = s.data();

    // analogous d = s.data();
    d = Singleton::instance().data();
    return 0;

    return 0;
}
