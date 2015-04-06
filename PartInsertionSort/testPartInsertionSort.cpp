#include "partInsertionSort.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::function;

int main()
{
  vector<int> aVec({14, 2, 6, 8, 15, 10, 7, 1, 13, 9, 12, 4, 11, 5, 19, 3});
  
  for_each(aVec.begin(), aVec.end(), [](int x) { cout << x << " "; });
  cout << endl;

  int i = 4, j = 12;
  cout << "Before insertionSort" << endl;
  insertionSort(aVec, i, j);
  cout << "After insertionSort" << endl;
  for_each(aVec.begin(), aVec.end(), [](int x) { cout << x << " "; });
  cout << endl;

  return 0;
}
