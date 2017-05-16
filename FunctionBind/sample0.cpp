#include <iostream>
#include <string>
#include <functional>

bool check_size(const std::string &s, std::string::size_type sz)
{
  return s.size() >= sz;
}

int main()
{
  auto check6 = std::bind(check_size, std::placeholders::_1, 6);
  std::string s("hello");
  bool b1 = check6(s);
}
