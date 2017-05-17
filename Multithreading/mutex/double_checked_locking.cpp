#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::vector;
using std::thread;
using std::mutex;
using std::unique_lock;

class MyClass
{
public:
  void init() { cout << "Init" << endl; }
};

MyClass var;
bool initialized = false;
mutex mut;

void func()
{
  if (!initialized) {
    unique_lock<mutex> lock(mut);
    if (!initialized) {
      var.init();
      initialized = true;
    }
  }
  cout << "OK" << endl;
}

int main(void)
{
  cout.sync_with_stdio(true);
  vector<thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.push_back(thread{func});
  }
  for (auto& t : threads) t.join();

  return 0;
}
