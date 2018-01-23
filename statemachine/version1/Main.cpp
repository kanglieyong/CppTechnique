#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <iostream>

namespace sc = boost::statechart;

// forward-declare initial state
struct Greeting;

struct Machine : sc::state_machine<Machine, Greeting> {};

struct Greeting : sc::simple_state<Greeting, Machine>
{
  Greeting()  { std::cout << "Hello World!\n"; }
  ~Greeting() { std::cout << "Bye Bye World!\n"; }
};

int main()
{
  Machine myMachine;
  myMachine.initiate();

  return 0;
}
