#include <iostream>
using std::cout;
using std::endl;

int main()
{
  int x = [](int t){ return t * t; }(10);
  cout << x << endl;

  auto func = [](int t) { return t * t / 2; };
  int y = func(10);
  cout << y << endl;
  
  return 0;
}
