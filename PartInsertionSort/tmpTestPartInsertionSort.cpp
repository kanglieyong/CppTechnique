#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void showVec(const vector<int>& a)
{
  for (auto & x : a) {
    cout << x << " ";
  }
  cout << endl;
}

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right)
{
  int j;

  for (int p = 1; p < right - left; p++) {
    Comparable tmp = a[left + p];
    for (j = left + p; j > left && tmp < a[j - 1]; j--) {
      a[j] = a[j - 1];
    }
    a[j] = tmp;
  }
}

int main()
{
  vector<int> aVec({10, 5, 3, 2, 7, 8, 4, 6, 1, 9});
  showVec(aVec);
  int head = 2, tail = 7;
  cout << "head = " << head << ", tail = " << tail << endl;
  insertionSort(aVec, head, tail);
  showVec(aVec);

  return 0;
}
