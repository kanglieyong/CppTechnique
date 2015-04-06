#include <vector>

using std::vector;

template <typename Comparable>
void partInsertionSort(vector<Comparable>& a, int left, int right)
{
  int j;

  for (int p = 1; p < right - left + 1; p++) {
    Comparable tmp = a[left + 1];
    for (j = left + p; j > 0)
  }
}
