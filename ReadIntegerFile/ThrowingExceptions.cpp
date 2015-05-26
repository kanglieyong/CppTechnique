#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::invalid_argument;
using std::runtime_error;

void readIntegerFile(const string& fileName, vector<int>& dest)
{
  ifstream istr;
  int temp;
  istr.open(fileName.c_str());
  if (istr.fail()) throw invalid_argument("");

  while (istr >> temp) {
    dest.push_back(temp);
  }

  if (istr.eof()) {
    istr.close();
  } else {
    istr.close();
    throw runtime_error("");
  }
}

int main(void)
{
  vector<int> dest;
  const string fileName("log.out");

  try {
    readIntegerFile(fileName, dest);
  } catch (const invalid_argument& e) {
    cerr << "Unable to open file " << fileName << endl;
    return 1;
  } catch (const runtime_error& e) {
    cerr << "Error reading file " << fileName << endl;
    return 1;
  }

  for (auto& x : dest) {
    cout << x << endl;
  }

  return 0;
}
