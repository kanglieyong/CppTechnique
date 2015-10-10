#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::endl;
using std::string;

using std::type_info;

class Base {
public:
  Base(const string& inMessage)
    : mMessage(inMessage)
  {
  }

  virtual string getLogMessage() const {
    return mMessage;
  }

  virtual ~Base() {
  }
  
private:
  string mMessage;
};

class Derived : public Base
{
public:
  Derived(const string& inMessage)
    : Base(inMessage)
  {}

  virtual string getLogMessage() const {
    return Base::getLogMessage() + " from Base";
  }

  virtual ~Derived() {}
};

void speak(const Base& inObj)
{
  if (typeid(inObj) == typeid(Base&)) {
    cout << "Base" << endl;
  } else if (typeid(inObj) == typeid(Derived&)) {
    cout << "Derived" << endl;
  }
}

void logObject(const Base& inLoggableObject) {
  cout << typeid(inLoggableObject).name() << "  ";
  cout << inLoggableObject.getLogMessage() << endl;
}


int main()
{
  Base* base = new Base("Hello, Base");
  Derived* derived  = new Derived("Hello, Derived");

  cout << "Type info" << endl;

  cout << base->getLogMessage() << endl;
  cout << derived->getLogMessage() << endl;

  delete base;
  delete derived;

  cout << "Next" << endl;

  Base b("base");
  Derived d("derived");

  speak(d);

  logObject(b);

  return 0;
}
