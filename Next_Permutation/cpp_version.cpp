#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  std::string str;
  std::cin >> str;
  std::sort(str.begin(), str.end());
  std::cout << str << std::endl;

  while (std::next_permutation(str.begin(), str.end())) {
    std::cout << str << std::endl; 
  }

  return 0;
}
