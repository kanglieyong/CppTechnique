#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::runtime_error;
using std::invalid_argument;

class FileError : public runtime_error
{
public:
  FileError(const string& fileIn)
    : runtime_error(""),
      mFile(fileIn) {}

  virtual const char* what() const noexcept { return mMsg.c_str(); }
  const string getFileName() const { return mFile; }
  
protected:
  string mFile, mMsg;
};

class FileOpenError : public FileError
{
public:
  FileOpenError(const string& fileNameIn);
};

class FileReadError : public FileError
{
public:
  FileReadError(const string& fileNameIn, int lineNumIn);
  const int getLineNum() const { return mLineNum; }

protected:
  int mLineNum;
};

FileOpenError::FileOpenError(const string& fileNameIn)
  : FileError(fileNameIn)
{

  mMsg = "Unable to open " + fileNameIn;
}

FileReadError::FileReadError(const string& fileNameIn, int lineNumIn)
  : FileError(fileNameIn),
    mLineNum(lineNumIn)
{
  ostringstream ostr;
  ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
  mMsg = ostr.str();
}


void readIntegerFile(const string& fileName, vector<int>& dest) throw (FileOpenError, FileReadError);

int main(void)
{
  vector<int> dest;
  const string fileName("GoneWithTheWind.txt");
  try {
    readIntegerFile(fileName, dest);
  } catch (const FileError& e) {
    cerr << e.what() << endl;
    return 1;
  }

  for (auto& x : dest) cout << x << " ";
  cout << endl;

  return 0;
}

void readIntegerFile(const string& fileName, vector<int>& dest) throw (FileOpenError, FileReadError)
{
  ifstream istr;
  int temp;
  string line;
  int lineNumber = 0;
  istr.open(fileName.c_str());
  if (istr.fail()) throw FileOpenError(fileName);

  while (!istr.eof()) {
    getline(istr, line);
    lineNumber++;
    istringstream lineStream(line);
    while (lineStream >> temp) dest.push_back(temp);

    if (!lineStream.eof()) {
      istr.close();
      throw FileReadError(fileName, lineNumber);
    }
  }
  istr.close();
}
