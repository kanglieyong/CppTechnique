// Observer.h
// The Observer interface.

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observable;
class Argument {};

class Observer
{
 public:
  // Called by the observed object, whenever
  // the observed object is changed.

  virtual void update(Observable* o, Argument* arg) = 0;
  virtual ~Observer() {}
};

#endif
