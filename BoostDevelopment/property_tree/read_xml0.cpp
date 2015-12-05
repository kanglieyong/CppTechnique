#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <iostream>

using namespace std;
using namespace boost::property_tree;

int main()
{
  ptree pt;
  read_xml("conf.xml", pt);

  cout << pt.get<string>("conf.theme") << endl;
  cout << pt.get<int>("conf.clock_style") << endl;
  cout << pt.get<long>("conf.gui") << endl;
  cout << pt.get("conf.no_prop", 100) << endl;

  auto child = pt.get_child("conf.urls");
  for (auto& x : child) {
    cout << x.second.data() << ", ";
  }
  cout << endl;

  return 0;
}
