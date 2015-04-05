#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::make_pair;

template <typename T>
void printMap(const T& m)
{
  for (auto & p : m) {
    cout << p.first << "(Phone: " << p.second << ")" << endl;
  }
  cout << "-------------" << endl;
}

int main()
{
  // Create a hash table.
  unordered_map<string, string> um;
  um.insert({
      {"Rhett Bulter", "842-876543"},
	{"Scarlett Ohara", "123-543222"},
	  {"Tom Cat", "654-987321"}
    });
  printMap(um);

  // Add / remove some phone numbers.
  um.insert(make_pair("John Donne", "532-987653"));
  um["Harry Potter"] = "432-987654";
  um["Freddy K."] = "999-123455";
  um.erase("Freddy K.");
  printMap(um);

  // Find the bucket index for a specific key.
  int bucket = um.bucket("Scarlett Ohara");
  cout << "Scarlett Ohara is in bucket " << bucket
       << " which contains the following "
       << um.bucket_size(bucket) << " elements: " << endl;

  auto liter = um.cbegin(bucket);
  auto literEnd = um.cend(bucket);
  while (liter != literEnd) {
    cout << "\t" << liter->first << "(Phone: "
	 << liter->second << ")" << endl;
    ++liter;
  }
  cout <<  "-----------" << endl;

  cout << "There are " << um.bucket_count() << " buckets." << endl;
  cout << "Average number of elements in a bucket is " << um.load_factor() << endl;

  return 0;
}
