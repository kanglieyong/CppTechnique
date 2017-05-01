#include <stdio.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define ABS(X) ((X) < 0 ? -(X) : (X))
#define ISSIGN(X) ((X) == '+' || (X) == '-' ? 1 : 0)
#define PR(X) printf("the result is %d.\n", X);
int main()
{
  int x1, x2, x3;
  x1 = MAX(4, 7);
  x2 = ABS(-10);

  PR(x1);
  PR(x2);

  return 0;
}
