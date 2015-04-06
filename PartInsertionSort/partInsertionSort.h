#include <vector>

using std::vector;

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right)
{
  int j;

  for (int p = 1; p < right - left + 1; p++) {
    Comparable tmp = a[left + p];
    for (j = p; j - p > 0 && tmp < a[j - 1]; j--) {
      a[j] = a[j - 1];
    }
    a[j] = tmp;
  }
}
