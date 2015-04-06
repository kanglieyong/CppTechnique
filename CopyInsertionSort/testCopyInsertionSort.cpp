#include "copyInsertionSort.h"
#include <algorithm>

using std::function;

int main()
{
  int arr[16] = {14, 2, 6, 8, 15, 10, 7, 1, 13, 9, 12, 4, 11, 5, 19, 3};
  vector<int> aVec(16);
  copy(arr, arr + 16, aVec.begin());
  
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
