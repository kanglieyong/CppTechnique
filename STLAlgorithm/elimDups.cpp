#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
  for (auto &x : words) std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
