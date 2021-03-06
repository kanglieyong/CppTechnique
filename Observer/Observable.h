// Observable.h
// The Observable class.

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <set>
#include "Observer.h"

class Observable
{
 private:
  bool changed;
  std::set<Observer*> observers;

 protected:
  virtual void setChanged() { changed = true; }
  virtual void clearChanged() { changed = false; }
  
 public:
  virtual void addObserver(Observer& o)
  {
    observers.insert(&o);
  }
  virtual void deleteObserver(Observer& o) { observers.erase(&o); }
  virtual void deleteObservers() { observers.clear(); }
  virtual int countObservers() { return observers.size(); }
  virtual bool hasChanged() { return changed; }
  virtual void notifyObservers(Argument* arg = 0)
  {
    if (!hasChanged()) return;
    clearChanged(); // Not "changed" anymore
    std::set<Observer*>::iterator it;
    for (it = observers.begin(); it != observers.end(); ++it) {
      (*it)->update(this, arg);
    }
  }
  virtual ~Observable() {}
};

#endif
