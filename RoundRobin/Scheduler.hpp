#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "RoundRobin.hpp"
#include "Process.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::out_of_range;

class Scheduler
{
public:
  Scheduler(const vector<Process>& processes);
  
  void scheduleTimeSlice();
  void removeProcess(const Process& process);
  
protected:
  RoundRobin<Process> rr;
};

#endif

Scheduler::Scheduler(const vector<Process>& processes)
{
  for (auto& process : processes) {
    rr.add(process);
  }
}

void Scheduler::scheduleTimeSlice()
{
  try {
    rr.getNext().doWorkDuringTimeSlice();
  } catch (out_of_range) {
    cerr << "No more processes to schedule." << endl;
  }
}

void Scheduler::removeProcess(const Process& process)
{
  rr.remove(process);
}
