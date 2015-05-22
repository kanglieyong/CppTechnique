#include "Process.h"
#include "Scheduler.hpp"

#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::stringstream;
using std::vector;

int main(void)
{
  vector<Process> processes;
  for (int i = 0; i < 7; i++) {
    stringstream ss;
    string str;
    ss << i;
    ss >> str;
    str = "Process " + str;
    processes.push_back(Process(str));
  }
  Scheduler sched(processes);

  for (int i = 0; i < 13; i++) sched.scheduleTimeSlice();

  sched.removeProcess(processes[2]);
  cout << "Removed third process" << endl;
  for (int i = 0; i < 13; i++) sched.scheduleTimeSlice();

  return 0;
}
