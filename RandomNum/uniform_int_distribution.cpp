#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <algorithm>
#include <time.h>

using std::cout;
using std::endl;
using std::map;
using std::ofstream;
using std::mt19937;
using std::uniform_int_distribution;
using std::function;

int main(void)
{
  const unsigned int DIST_START = 1;
  const unsigned int DIST_END = 99;
  const unsigned int ITERATIONS = 1000000;

  mt19937 eng(static_cast<unsigned long>(time(nullptr)));
  uniform_int_distribution<int> dist(DIST_START, DIST_END);
  auto gen = bind(dist, eng);
  map<int, int> m;
  for (unsigned int i = 0; i < ITERATIONS; ++i) {
    int rnd = gen();
    ++m[rnd];
  }

  ofstream of("res.csv");
  for (unsigned int i = DIST_START; i <= DIST_END; ++i) {
    of << i << ",";
    auto res = m.find(i);
    of << (res != m.end() ? res->second : 0) << endl;
  }
  
  return 0;
}

