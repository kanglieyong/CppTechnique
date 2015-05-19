#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

bool isEven(int num)
{
  return num % 2 == 0;
}

int main(void)
{
  vector<int> vec;
  for (int i = 0; i < 10; i++) vec.push_back(i);

  auto f2 = isEven;
  int cnt = count_if(vec.cbegin(), vec.cend(), f2);
  cout << cnt << " even numbers" << endl;
  
  return 0;
}
