#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void constString()
{
  const string a = "Hello";
  cout << a << endl;

  const string& aa = a;
  string& r = const_cast<string&>(aa);

  r = "hello";

  cout << "Object version: " << endl;

  cout << "a = "  << a  << endl;
  cout << "aa = " << aa << endl;
  cout << "r = "  << r  << endl << endl;
}

void constChar()
{
  const char a = 'Z';
  cout << a << endl;

  const char& aa = a;
  char& r = const_cast<char&>(aa);

  r = 'X';

  cout << "Char version: " << endl;

  cout << "a = "  << a  << endl;
  cout << "aa = " << aa << endl;
  cout << "r = "  << r  << endl << endl;
}

void constInt()
{
  const int a = 10;
  cout << a << endl;

  const int& aa = a;
  int& r = const_cast<int&>(aa);

  r = 21;

  cout << "Int version: " << endl;

  cout << "a = " << a << endl;
  cout << "aa = " << aa << endl;
  cout << "r = " << r << endl << endl;
}

int main(void)
{
  constString();
  constChar();
  constInt();

  return 0;
}
