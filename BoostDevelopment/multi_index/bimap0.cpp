#include <boost/bimap.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

int main()
{
  bimap<int ,string> bm;

  bm.left.insert(make_pair(1, "111"));
  bm.left.insert(make_pair(2, "222"));

  bm.right.insert(make_pair("string", 10));
  bm.right.insert(make_pair("bimap", 20));

  for (auto pos = bm.left.begin(); pos != bm.left.end(); ++pos) {
    cout << "left[" << pos->first << "]=" << pos->second << endl;
  }
  cout << endl;

  for (auto& x : bm.right) {
    cout << "right[" << x.first << "]=" << x.second << endl;
  }
  cout << endl;

  return 0;
}
