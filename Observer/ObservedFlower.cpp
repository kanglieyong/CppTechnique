// ObservedFlower.cpp
// Demonstration of "observer" pattern.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Observable.h"
using namespace std;

class Flower
{
private:
  bool isOpen;

public:
  Flower()
    : isOpen(false),
      openNotifier(this),
      closeNotifier(this)
  {}

  void open()
  {
    isOpen = true;
    openNotifier.notifyObservers();
    closeNotifier.open();
  }

  void close()
  {
    isOpen = false;
    closeNotifier.notifyObservers();
    openNotifier.close();
  }

  class OpenNotifier;
  friend class Flower::OpenNotifier;
  class OpenNotifier : public Observable
  {
  private:
    Flower* parent;
    bool alreadyOpen;

  public:
    OpenNotifier(Flower* f)
      : parent(f),
	alreadyOpen(false)
    {}

    void notifyObservers(Argument* arg = 0)
    {
      if (parent->isOpen && !alreadyOpen) {
	setChanged();
	Observable::notifyObservers();
	alreadyOpen = true;
      }
    }

    void close() { alreadyOpen = false; }
  } openNotifier;

  class CloseNotifier;
  friend class Flower::CloseNotifier;
  class CloseNotifier : public Observable
  {
  private:
    Flower* parent;
    bool alreadyClosed;

  public:
    CloseNotifier(Flower* f)
      : parent(f),
	alreadyClosed(false)
    {}

    void notifyObservers(Argument* arg = 0)
    {
      if (!parent->isOpen && !alreadyClosed) {
	setChanged();
	Observable::notifyObservers();
	alreadyClosed = true;
      }
    }

    void open() { alreadyClosed = false; }
  } closeNotifier;
};

class Bee
{
private:
  string name;

  class OpenObserver;
  friend class Bee::OpenObserver;
  class OpenObserver : public Observer
  {
  private:
    Bee* parent;
    
  public:
    OpenObserver(Bee* b)
      : parent(b)
    {}

    void update(Observable* , Argument* )
    {
      cout << "Bee " << parent->name
	   << "'s breakfast time!" << endl;
    }
  } openObsrv;

  class CloseObserver;
  friend class Bee::CloseObserver;
  class CloseObserver : public Observer
  {
  private:
    Bee* parent;
    
  public:
    CloseObserver(Bee* b)
      : parent(b)
    {}

    void update(Observable* , Argument* )
    {
      cout << "Bee " << parent->name
	   <<	"'s bed time" << endl;
    }
  } closeObsrv;

public:
  Bee(string nm)
    : name(nm),
      openObsrv(this),
      closeObsrv(this)
  {}

  Observer& openObserver() { return openObsrv; }

  Observer& closeObserver() { return closeObsrv; }
};

class Hummingbird
{
private:
  string name;
  
  class OpenObserver;
  friend class Hummingbird::OpenObserver;
  class OpenObserver : public Observer
  {
  private:
    Hummingbird* parent;

  public:
    OpenObserver(Hummingbird* h)
      : parent(h)
    {}

    void update(Observable* , Argument* )
    {
      cout << "Hummingbird " << parent->name
	   << "'s breakfast time!" << endl;
    }
  } openObsrv;

  class CloseObserver;
  friend class Hummingbird::CloseObserver;
  class CloseObserver : public Observer
  {
  private:
    Hummingbird* parent;
    
  public:
    CloseObserver(Hummingbird* h)
      : parent(h)
    {}

    void update(Observable* , Argument* )
    {
      cout << "Hummingbird " << parent->name
	   << "'s bed time!" << endl;
    }
  } closeObsrv;

public:
  Hummingbird(string nm)
    : name(nm),
      openObsrv(this),
      closeObsrv(this)
  {}

  Observer& openObserver() { return openObsrv; }
  Observer& closeObserver() { return closeObsrv; }
};

int main()
{
  Flower f;
  Bee ba("A"), bb("B");
  Hummingbird ha("A"), hb("B");

  f.openNotifier.addObserver(ba.openObserver());
  f.openNotifier.addObserver(bb.openObserver());
  f.openNotifier.addObserver(ha.openObserver());
  f.openNotifier.addObserver(hb.openObserver());

  f.closeNotifier.addObserver(ba.closeObserver());
  f.closeNotifier.addObserver(bb.closeObserver());
  f.closeNotifier.addObserver(ha.closeObserver());
  f.closeNotifier.addObserver(hb.closeObserver());

  f.openNotifier.deleteObserver(hb.openObserver());

  f.open();

  f.closeNotifier.deleteObserver(ba.closeObserver());
  f.close();
  f.openNotifier.deleteObservers();
  f.open();
  f.close();

  return 0;
}
