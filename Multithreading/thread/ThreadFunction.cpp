#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void counter(int id, int numIterations)
{
  for (int i = 0; i < numIterations; i++) {
    cout << "Counter " << id << " has value ";
    cout << i << endl;
  }
}

int main(void)
{
  cout.sync_with_stdio(true);
  thread t1(counter, 1, 6);
  thread t2(counter, 2, 5);

  t1.join();
  t2.join();

  return 0;
}
