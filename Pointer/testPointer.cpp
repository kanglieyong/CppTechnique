#include "Pointer.h"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
  Pointer<int> smartInt(new int);
  *smartInt = 5;
  cout << *smartInt << endl;

  return 0;
}
