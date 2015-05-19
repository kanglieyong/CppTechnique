#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;
using std::mt19937;
using std::uniform_int_distribution;
using std::function;

int main(void)
{
  mt19937 eng(static_cast<unsigned long>(time(nullptr)));
  uniform_int_distribution<int> dist(1, 99);

  auto gen = bind(dist, eng);
  vector<int> vec(10);

  generate(vec.begin(), vec.end(), gen);
  for (auto i : vec) cout << i << " ";
  cout << endl;
  
  return 0;
}
