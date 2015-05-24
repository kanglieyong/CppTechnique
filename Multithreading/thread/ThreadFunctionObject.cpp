#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Counter
{
public:
  Counter(int id, int numIterations)
    : mId(id),
      mNumIterations(numIterations)
  {}

  void operator()()
  {
    for (int i = 0; i < mNumIterations; i++) {
      cout << "Counter " << mId << " has value ";
      cout << i << endl;
    }
  }
  
protected:
  int mId;
  int mNumIterations;
};

int main(void)
{
  cout.sync_with_stdio(true);
  thread t1{Counter(1, 20)};
  Counter c(2, 12);
  thread t2(c);
  thread t3(Counter(3, 10));

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
