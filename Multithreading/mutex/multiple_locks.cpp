#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::thread;
using std::mutex;
using std::unique_lock;
using std::defer_lock_t;

mutex mut1;
mutex mut2;

void process()
{
  unique_lock<mutex> lock1(mut1, defer_lock_t());
  unique_lock<mutex> lock2(mut2, defer_lock_t());

  lock(lock1, lock2);
  cout << "Done!" << endl;
}

void process2()
{
  unique_lock<mutex> lock1(mut1, defer_lock_t());
  unique_lock<mutex> lock2(mut2, defer_lock_t());

  lock(lock2, lock1);
  cout << "Done process2!" << endl;
}

int main(void)
{
  cout.sync_with_stdio(true);
  thread t(process2);

  t.join();

  return 0;
}
