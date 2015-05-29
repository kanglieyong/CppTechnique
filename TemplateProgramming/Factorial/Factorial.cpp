#include <iostream>

using std::cout;
using std::endl;

template <long long f>
class Factorial
{
public:
  static const long long val = (f * Factorial<f-1>::val);
};

template <>
class Factorial<1>
{
public:
  static const long long val = 1;
};

int main(void)
{
  cout << Factorial<6>::val << endl;
  //
  return 0;
}
