#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

int main(void)
{
  cout.sync_with_stdio(true);
  thread t1([](int id, int numIterations) {
    for (int i = 0; i < numIterations; i++) {
      cout << "Counter " << id << " has value ";
      cout << i << endl;
    }
  }, 1, 5);
  t1.join();

  return 0;
}
