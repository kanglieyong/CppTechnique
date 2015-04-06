/*
 * Simple insertion sort.
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right)
{
  vector<Comparable> tmpArray(right - left + 1);
  copy(a.begin() + left, a.begin() + right, tmpArray.begin());
  cout << "Get here? Copy vector a to tmpArray " << endl;
  
  int j;

  for (int p = 1; p < tmpArray.size(); p++) {
    Comparable tmp = tmpArray[p];
    for (j = p; j > 0 && tmp < tmpArray[j - 1]; j--) {
      tmpArray[j] = tmpArray[j - 1];
    }
    tmpArray[j] = tmp;
  }
  cout << "Get here? insertion completed" << endl;
  
  for (int i = 0; i < right - left + 1; i++) {
    a[left + i] = tmpArray[i];
  }
  cout << "Get here? copy vector tmpArray to a completed " << endl;
}
