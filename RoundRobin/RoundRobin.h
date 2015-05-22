#ifndef ROUNDROBIN_H_
#Define ROUNDROBIN_H_

#include <vector>
#include <stdexcept>

template <typename T>
class RoundRobin
{
 public:
  RoundRobin(int numExpected = 0);
  virtual ~RoundRobin();

  void add(const T& elem);
  void remove(const T& elem);
  T& getNext() throw (std::out_of_range);

 protected:
  std::vector<T> mElems;
  typename std::vector<T>::iterator mCurElem;
  
 private:
  RoundRobin(const RoundRobin& src);
  RoundRobin& operator=(const RoundRobin& rhs);
};

#endif
