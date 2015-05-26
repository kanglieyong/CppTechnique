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

void readIntegerFile(const string& fileName, vector<int>& dest) throw(invalid_argument, runtime_error)
{
  ifstream istr;
  int temp;
  istr.open(fileName.c_str());
  if (istr.fail()) {
    string error = "Unable to open file " + fileName;
    throw invalid_argument(error);
  }

  while (istr >> temp) {
    dest.push_back(temp);
  }

  if (istr.eof()) {
    istr.close();
  } else {
    istr.close();
    string error = "Unable to read file " + fileName;
    throw runtime_error(error);
  }
}

int main(void)
{
  vector<int> dest;
  const string fileName("log.out");

  try {
    readIntegerFile(fileName, dest);
  } catch (const invalid_argument& e) {
    cerr << e.what() << endl;
    return 1;
  } catch (const runtime_error& e) {
    cerr << e.what() << endl;
    return 1;
  }

  for (auto& x : dest) {
    cout << x << endl;
  }

  return 0;
}
