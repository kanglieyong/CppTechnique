#include "partInsertionSort.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::function;

static const int Begin = 4, End = 12;

void printVec(const vector<int>& a)
{
  int size = a.size();
  for (int i = 0; i < a.size(); i++) {
    if (i == Begin || i == End) {
      cout << endl;
    }
    cout << a[i] << " ";
  }
}

int main()
{
  vector<int> aVec({14, 2, 6, 8, 15, 10, 7, 1, 13, 9, 12, 4, 11, 5, 19, 3});
  
  for_each(aVec.begin(), aVec.end(), [](int x) { cout << x << " "; });
  cout << endl;
  
  vector<int> bVec(aVec);
  sort(bVec.begin(), bVec.end());
  for_each(bVec.begin(), bVec.end(), [](int x) { cout << x << " "; });
  cout << endl;

  cout << "Before insertionSort" << endl;
  insertionSort(aVec, Begin, End);
  cout << "After insertionSort" << endl;
  printVec(aVec);
  cout << endl;

  return 0;
}
