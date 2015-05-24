#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void func1(void)
{
  cout << __func__ << endl;
}

void func2(int i)
{
  cout << "i = " << i << ", and function name: " << __func__ << endl;
  string s = __func__;
  cout << s << endl;
}

int main(void)
{
  func1();
  func2(10);

  return 0;
}
