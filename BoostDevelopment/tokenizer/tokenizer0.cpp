#include <boost/tokenizer.hpp>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

using namespace boost;

int main()
{
  string str("Link raise the master-sword.");

  tokenizer<> tok(str);

  for (auto x : tok) {
    cout << "[" << x << "]";
  }
  cout << endl;

  return 0;
}
