/*
 * Simple insertion sort.
 */
#include <vector>

using std::vector;

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right)
{
  vector<Comparable> tmpArray(right - left);
  copy(a.begin() + left, a.begin() + right, tmpArray.begin());
  
  int j;

  for (int p = 1; p < tmpArray.size(); p++) {
    Comparable tmp = tmpArray[p];
    for (j = p; j > 0 && tmp < tmpArray[j - 1]; j--) {
      tmpArray[j] = tmpArray[j - 1];
    }
    tmpArray[j] = tmp;
  }
  
  for (int i = 0; i < right - left; i++) {
    a[left + i] = tmpArray[i];
  }
}
