#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;

mutex mMut;

void print_block(const char c, int size)
{
  mMut.lock();
  for (int i = 0; i < size; i++) cout << c;
  cout << '\n';
  mMut.unlock();
}

int main(void)
{
  thread t1(print_block, '$', 20);
  thread t2(print_block, '*', 30);

  t1.join();
  t2.join();

  return 0;
}
