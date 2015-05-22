#include "Process.h"
#include "Scheduler.hpp"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

int main(void)
{
  vector<Process> processes;
  for (int i = 0; i < 7; i++) {
    string str = "Process " + to_string(i);
    processes.push_back(Process(str));
  }
  Scheduler sched(processes);

  for (int i = 0; i < 13; i++) sched.scheduleTimeSlice();

  sched.removeProcess(processes[2]);
  cout << "Removed third process" << endl;
  for (int i = 0; i < 13; i++) sched.scheduleTimeSlice();

  return 0;
}
