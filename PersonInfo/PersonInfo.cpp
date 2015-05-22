#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

struct PersonInfo
{
  string name;
  vector<string> phones;
};

int main(void)
{
  string line, word;
  vector<PersonInfo> people;
  while (getline(cin, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
  cout<< "Display people!" << endl;

  for (const auto& entry : people) {
    cout << "name: " << entry.name << ", phone number: ";
    for (auto& phone : entry.phones) {
      cout << phone << " ";
    }
    cout << endl;
  }
  
  return 0;
}
