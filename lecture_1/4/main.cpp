// #include <iostream>
// using namespace std;

void bar()
{
    int c;
    // cout << "bar launched" << endl;
}

void foo()
{
    // cout << "foo launched" << endl;
    int b = 3;
    bar();
    // cout << "foo finished" << endl;
}

int main()
{
    int a = 3;
    foo();
    bar();

    return 0;
}
