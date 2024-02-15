// C++ program to illustrate macros
#include <iostream>
using namespace std;

// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b))

// Driver Code
int main()
{

	// Given two number a and b
	int a = 18;
	int b = 76;

	cout << "Minimum value between"
		<< a << " and " << b
		<< " is: " << min(a, b);

	return 0;
}
