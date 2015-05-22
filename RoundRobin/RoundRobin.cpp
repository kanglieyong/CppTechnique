#include "RoundRobin.h"

template <typename T>
RoundRobin<T>::RoundRobin(int numExpected)
  : mElems(numExpected),
    mCurElem(mElems.begin())
{}

template <typename T>
RoundRobin<T>::~RoundRobin()
{
}

template <typename T>
void RoundRobin<T>::add(const T& elem)
{
  int pos = mCurElem - mElems.begin();
  mElems.push_back(elem);
  mCurElem = mElems.begin() + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& elem)
{
  for (auto it = mElems.begin(); it != mElems.end(); ++it) {
    if (*it == elem) {
      int newPos;
      if (mCurElem <= it) {
	newPos = mCurElem - mElems.begin();
      } else {
	newPos = mCurElem - mElems.begin() - 1;
      }
      mElems.erase(it);
      mCurElem = mElems.begin() + newPos;
      if (mCurElem == mElems.end()) mCurElem = mElems.begin();
      return;
    }
  }
}

template <typename T>
T& RoundRobin<T>::getNext() throw (std::out_of_range)
{
  if (mElems.empty()) throw std::out_of_range("No element in the list");

  T& retVal = *mCurElem;
  ++mCurElem;
  if (mCurElem == mElems.end()) mCurElem = mElems.begin();

  return retVal;
}
