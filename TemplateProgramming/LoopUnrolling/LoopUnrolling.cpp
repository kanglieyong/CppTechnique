#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::function;

template <int i, typename FuncType>
class Loop
{
public:
  static inline void Do(FuncType func)
  {
    Loop<i-1, FuncType>::Do(func);
    func(i);
  }
};

template <typename FuncType>
class Loop<-1, FuncType>
{
 public:
  static inline void Do(FuncType func) {}
};

void DoWork(int i) { cout << "DoWork(" << i << ")" << endl; }

int main(void)
{
  Loop<3, function<void(int)>>::Do(DoWork);

  return 0;
}
