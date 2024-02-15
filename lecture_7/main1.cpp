// статическая локальная переменная – глоб. переменная, доступная только в пределах функции
// от первого вызова программы до конца функции

int next(int start = 0)
{
    static int k = start;
    return k;
}

// статические глобальные пременные
// статик копируется на каждый модуль;
// инитятся в

// Статические локальные переменные
// глобальная переменная доступная только в пределах функции

// время жизни такой пременной – от первого вызова функции next до конца программы
int next(int start = 0)
{
    // игнорируется при последующих вызовах
    static int k = start;
    return k++;
}

// static functions
// доступна только в пределах модуля
static void test()
{
    int a = 0;
};

// проходят внутреннюю линковку;

// Типы линковки
// internal в рамках одной единицы трансляции (.cpp files)
// external
// static global var and funcs, функции в безымянном namespace
// проходят внутреннюю линковку по дефолту
//

// статические поля класса – глобальные переменные, определенные внутри класса

struct User
{

public:
    static int count() { return instances_; }
    static int instances_;
};

// static methods – funcs defined inside of a class with access
// to closed fields and methods

// declaration


int test1()
{
    User::count();
    int val = User::instances_;
    return 0;
}

// Inline
inline double square(double x) { return x * x; }

// в месте inline-функции должно быть известно ее определение
// inline функции можно определять в заголовочных файлах
// все функции, определенные внутри класса являются inline
// при линковке из всех версий inline-funcs (т.е. код из разных единиц трансляции) выбирается только одна
// все определения одной и той же inline-functions должны быть идентичны
// inline – совет компилятору
