#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

int main(void)
{
  bitset<10> myBitset;
  myBitset.set(3);
  myBitset.set(6);
  myBitset[8] = true;
  myBitset[9] = myBitset[3];
  
  if (myBitset.test(3)) cout << "Bit 3 is set!" << endl;
  cout << myBitset << endl;

  return 0;
}
