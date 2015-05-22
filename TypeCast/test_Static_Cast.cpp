#include <iostream>

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
  d->info();

  d = static_cast<Derived*>(b);
  b->info();
  d->info();
  
  Base base; base.info();
  Derived derived;

  Base& br = derived;
  br.info();
  Derived& dr = static_cast<Derived&>(br);
  dr.info();

  delete d;
  
  return 0;
}
