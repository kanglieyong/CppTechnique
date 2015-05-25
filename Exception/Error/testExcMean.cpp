#include "exc_mean.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void)

{
  bad_hmean g;
  g.mesg();
  
  bad_gmean h;
  cout << h.mesg() << endl;

  cout << "h.v1 = " << h.v1 << ", h.v2 = " << h.v2 << endl;
  
  return 0;
}
