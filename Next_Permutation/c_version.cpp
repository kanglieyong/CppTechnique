#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 100

int main()
{
  int length;
  char str[MAX];
  gets(str);
  length = strlen(str);
  std::sort(str, str+length);
  puts(str);
  while (std::next_permutation(str, str+length)) {
    puts(str); 
  }
  return 0;
}
