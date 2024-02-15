#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // Declaring a vector
  vector<int> v = {1, 2, 3};
  vector<int>::iterator i;

  // Declaring an iterator
  int j;
  cout << "Without iterators = ";

  // Accessing the elements without using iterators
  for (j = 0; j < 3; ++j)
  {
    cout << v[j] << " ";
  }
  cout << "\nWith iterators = ";

  // Accessing the elements using iterators
  for (i = v.begin(); i != v.end(); ++i)
  {
    cout << *i << " ";
  }
  cout << endl;
  cout << v.end() - v.begin();

  // Adding one more element to vector
  v.push_back(4);
  cout << "\nWithout iterators = ";
  
  return 0;
}