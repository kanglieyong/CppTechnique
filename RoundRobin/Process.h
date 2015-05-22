#ifndef PROCESS_H_
#define PROCESS_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Process
{
public:
  Process(const string& name)
    : mName(name) {}

  void doWorkDuringTimeSlice()
  {
    cout << "Process " << mName << " performing work during time slice." << endl;
  }

  bool operator==(const Process& rhs)
  {
    return mName == rhs.mName;
  }
  
protected:
  string mName;
};

#endif
