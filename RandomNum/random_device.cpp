#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::random_device;

int main(void)
{
  random_device rnd;
  cout << "Entropy: " << rnd.entropy() << endl;
  cout << "Min value: " << rnd.min()
       << ", Max value: " << rnd.max() << endl;
  cout << "Random number:" << rnd() << endl;
  
  return 0;
}
