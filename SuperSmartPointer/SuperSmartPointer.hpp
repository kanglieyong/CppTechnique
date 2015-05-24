#ifndef SUPERSMARTPOINTER_H_
#define SUPERSMARTPOINTER_H_

#include <map>
#include <stdexcept>

template <typename T>
class SuperSmartPointer
{
public:
  explicit SuperSmartPointer(T* inPtr);
  virtual ~SuperSmartPointer();

  SuperSmartPointer(const SuperSmartPointer& src);
  SuperSmartPointer& operator=(const SuperSmartPointer& rhs);

  const T& operator*() const;
  const T* operator->() const;

  T& operator*();
  T* operator->();

  operator void*() const { return mPtr; }
  
protected:
  T* mPtr;
  static std::map<T*, int> sRefCountMap;

  void initPointer(T* inPtr);
  void finalizePointer();
};

#endif

// static member variable
template <typename T>
std::map<T*, int> SuperSmartPointer<T>::sRefCountMap;

// protected methods
template <typename T>
void SuperSmartPointer<T>::initPointer(T* inPtr)
{
  mPtr = inPtr;
  if (sRefCountMap.find(mPtr) == sRefCountMap.end()) {
    sRefCountMap[mPtr] = 1;
  } else {
    ++sRefCountMap[mPtr];
  }
}

template <typename T>
void SuperSmartPointer<T>::finalizePointer()
{
  if (sRefCountMap.find(mPtr) == sRefCountMap.end()) throw std::runtime_error("ERROR: Missing entry in map!");
  sRefCountMap[mPtr]--;
  if (sRefCountMap[mPtr] == 0) {
    sRefCountMap.erase(mPtr);
    delete mPtr;
    mPtr = nullptr;
  }
}

// member function
// constructor
template <typename T>
SuperSmartPointer<T>::SuperSmartPointer(T* inPtr)
{
  initPointer(inPtr);
}

// destructor
template <typename T>
SuperSmartPointer<T>::~SuperSmartPointer()
{
  finalizePointer();
}

// copy constructor
template <typename T>
SuperSmartPointer<T>::SuperSmartPointer(const SuperSmartPointer<T>& src)
{
  initPointer(src.mPtr);
}

// assign function
template <typename T>
SuperSmartPointer<T>& SuperSmartPointer<T>::operator=(const SuperSmartPointer<T>& rhs)
{
  if (this == &rhs) return *this;

  finalizePointer();
  initPointer(rhs.mPtr);
  return *this;
}

template <typename T>
const T& SuperSmartPointer<T>::operator*() const
{
  return *mPtr;
}

template <typename T>
const T* SuperSmartPointer<T>::operator->() const
{
  return mPtr;
}

template <typename T>
T& SuperSmartPointer<T>::operator*()
{
  return *mPtr;
}

template <typename T>
T* SuperSmartPointer<T>::operator->()
{
  return mPtr;
}
