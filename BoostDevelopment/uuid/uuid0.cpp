#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace boost::uuids;
using namespace std;

int main()
{
  uuid u;
  assert(uuid::static_size() == 16);
  assert(u.size() == 16);

  vector<unsigned char> v(16, 7);
  copy(v.begin(), v.end(), u.begin());
  assert(u.data[0] == u.data[1] && u.data[15] == 7);

  cout << u << endl;
  fill_n(u.data + 10, 6, 8);

  cout << u << endl;
}
