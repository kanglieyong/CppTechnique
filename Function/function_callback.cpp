#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::function;

void process(const vector<int>& vec, function<void(int)> f)
{
  for (auto& i : vec) f(i);
}

void print(int num) { cout << num << " "; }

int main(void)
{
  vector<int> vec;
  for (int i = 0; i < 10; ++i) vec.push_back(i);
  
  process(vec, print);
  cout << endl;
  
  int sum = 0;
  process(vec, [&sum](int num) { sum += num; });
  cout << "sum = " << sum << endl;
  
  return 0;
}
