#include <iostream>

using std::cout;
using std::endl;

using YesNoFcn = bool(*)(int, int);

bool intEqual(int inItem1, int inItem2) { return inItem1 == inItem2; }
bool bothOdd(int inItem1, int inItem2) { return inItem1 % 2 == 1 && inItem2 % 2 == 1; }

void findMatches(int values1[], int values2[], size_t numValues, YesNoFcn inFunc)
{
  for (size_t i = 0; i < numValues; i++) {
    if (inFunc(values1[i], values2[i])) {
      cout << "Match found at position " << i << " (" << values1[i] << ", " << values2[i] << ")" << endl;
    }
  }
}

int main(void)
{
  int arr1[] = {2, 5, 6, 9, 10, 1, 1};
  int arr2[] = {4, 4, 2, 9, 0, 3, 4};
  int arrSize = sizeof(arr1) / sizeof(arr1[0]);
  
  cout << "calling findMathes() using intEqual():" << endl;
  findMatches(arr1, arr2, arrSize, &intEqual);

  cout << "calling findMathes() using bothOdd():" << endl;
  findMatches(arr1, arr2, arrSize, &bothOdd);

  return 0;
}
