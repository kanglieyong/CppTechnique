#ifndef PROCESS_H_
#define PROCESS_H_

#include <iostream>
#include <string>

class Process
{
public:
  Process(const std::string& name)
    : mName(name) {}

  void doWorkDuringTimeSlice() const
  {
    std::cout << "Process " << mName << " performing work during time slice." << std::endl;
  }

  bool operator==(const Process& rhs) const
  {
    return mName == rhs.mName;
  }
  
protected:
  std::string mName;
};

#endif
