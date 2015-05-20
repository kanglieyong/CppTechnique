#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

int main(void)
{
  auto str1 = "0011001100";
  auto str2 = "0000111100";
  bitset<10> bitsOne(str1);
  bitset<10> bitsTwo(str2);

  cout << "bitsOne:   " << bitsOne << endl;
  cout << "bitsTwo:   " << bitsTwo << endl;

  auto bitsThree = bitsOne & bitsTwo;
  cout << "bitsThree: " << bitsThree << endl;
  bitsThree <<= 4;
  cout << bitsThree << endl;

  cout << "bitsOne, Before: " << bitsOne << endl;

  bitsOne >>= 4;

  cout << "bitsOne, after : " << bitsOne << endl;

  return 0;
}
