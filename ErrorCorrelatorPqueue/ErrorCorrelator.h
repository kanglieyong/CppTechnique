#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <queue>
#include <iostream>
#include <stdexcept>

class Error
{
  public:
    Error(int priority, const std::string& errMsg)
    : mPriority(priority), 
      mError(errMsg)
    {}

    int getPriority() const {
      return mPriority;
    }

    std::string getErrorString() const {
      return mError;
    }

    friend bool operator<(const Error& lhs, const Error& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Error& err);

  protected:
    int mPriority;
    std::string mError;
};

class ErrorCorrelator
{
  public:
    ErrorCorrelator() {}

    void addError(const Error& error);
    Error getError() throw(std::out_of_range);

  protected:
    std::priority_queue<Error> mErrors;
};

#endif
