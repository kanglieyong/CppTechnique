#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool isShorter(const std::string &s1, const std::string &s2)
{
  return s1.size() < s2.size();
}

bool check_size(const std::string &s, std::string::size_type sz)
{
  return s.size() >= sz;
}

void elimDups(std::vector<std::string> &words)
{
  std::sort(words.begin(), words.end(), std::bind(isShorter, std::placeholders::_2, std::placeholders::_1));
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
  elimDups(words);
  stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });
  auto wc = find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
  auto count = words.end() - wc;
  std::cout << count << " words of length " << sz << " or longer" << std::endl;
  std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
}

int main()
{
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  biggies(words, 4);
  //elimDups(words);
  //stable_sort(words.begin(), words.end(), isShorter); // dictionary sort
  //std::for_each(words.begin(), words.end(), [](const std::string &s) { std::cout << s << " "; });
  //for (auto &x : words) std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
