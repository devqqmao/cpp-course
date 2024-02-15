// Шаблоны

// Глобальные переменные
// Объявление глобальной переменной:

extern int global;

// может быть ошибка линковки;

void f()
{
    ++global;
}

// definition of global var
int global = 10;

// problems:
// scaling
// side effects
// order of initialization

// static global vars
// изменяемая
// доступна только в пределах модуля

static int global = 10;

void f()
{
    ++global;
}

int main()
{
    return 0;
}