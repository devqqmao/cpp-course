#include <iostream>
using namespace std; // позволяет не писать пр-во имен, которое используется
// перекрытие имен

int main()
{
    int a = 0;
    int b = 0;

    cout << "Enter a and b: " << endl;
    cin >> a >> b;

    cout << "(a + b) = " << (a + b) << endl;

    return 0;
}