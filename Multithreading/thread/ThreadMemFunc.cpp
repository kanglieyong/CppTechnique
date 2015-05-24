#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Request
{
public:
  Request(int id)
    : mId(id)
  {}

  void process() const
  {
    cout << "Processing request " << mId << endl;
  }
  
private:
  int mId;
};

int main(void)
{
  cout.sync_with_stdio(true);
  
  Request req(100);
  thread t{&Request::process, &req};
  t.join();

  return 0;
}
