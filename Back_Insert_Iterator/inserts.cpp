#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

void outPut(const std::string& s)
{
  std::cout << s << " ";
}

int main()
{
  using std::cout;
  using std::endl;
  using std::string;
  using std::vector;
  using std::insert_iterator;
  using std::back_insert_iterator;
  using std::function;

  string s1[4] = {"fine", "fish", "fashion", "fater"};
  string s2[2] = {"busy", "bats"};
  string s3[2] = {"silly", "singers"};

  vector<string> words(4);
  copy(s1, s1 + 4, words.begin());
  for_each(words.begin(), words.end(), outPut);
  cout << endl;

  copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));
  for_each(words.begin(), words.end(), outPut);
  cout << endl;

  copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin()));
  for_each(words.begin(), words.end(), outPut);
  cout << endl;

  return 0;
}
