#include <iostream>
#include <typeinfo>

class Base
{
public:
  Base() {}
  virtual ~Base() {}
  
  virtual void info() const { std::cout << "Base!" << std::endl; }
};

class Derived : public Base
{
public:
  Derived(int i = 10)
   : m_nValue(i) {}
  virtual ~Derived() {}

  virtual void info() const
  {
    std::cout << "Value: " << m_nValue << "--Derived!" << std::endl;
  }

private:
  int m_nValue;
};

int main(void)
{
  Base* b;
  Derived* d = new Derived();
  b = d;
  b->info();

  d = dynamic_cast<Derived*>(b);
  d->info();
  b->info();

  Base base;
  Derived derived;
  Base& br = base;
  try {
    Derived& dr = dynamic_cast<Derived&>(br);
  } catch ( const std::bad_cast&) {
    std::cout << "Bad cast!\n";
  }

  delete d;
  
  return 0;
}
