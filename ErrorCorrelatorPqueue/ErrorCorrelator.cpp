#include "ErrorCorrelator.h"

using std::ostream;
using std::string;
using std::priority_queue;

using std::out_of_range;

bool operator<(const Error& lhs, const Error& rhs)
{
  return (lhs.mPriority < rhs.mPriority);
}

ostream& operator<<(ostream& os, const Error& err)
{
  os << err.mError << "(priority " << err.mPriority << ")";
}

void ErrorCorrelator::addError(const Error& error)
{
  mErrors.push(error);
}

Error ErrorCorrelator::getError() throw(out_of_range)
{
  if (mErrors.empty()) {
    throw out_of_range("No elements!");
  }

  Error top = mErrors.top();
  mErrors.pop();

  return top;
}
