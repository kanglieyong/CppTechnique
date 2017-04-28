#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isShorter(const std::string &s1, const std::string &s2)
{
  return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words)
{
  std::sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

int main()
{
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  elimDups(words);
  stable_sort(words.begin(), words.end(), isShorter); // dictionary sort
  std::for_each(words.begin(), words.end(), [](const std::string &s) { std::cout << s << " "; });
  //for (auto &x : words) std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
