class Base
{
public:
  Base() {}
  virtual ~Base() {}
};

class Derived : public Base
{
public:
  Derived() {}
  virtual ~Derived() {}
};

int main()
{
  Base* b;
  Derived* d = new Derived();
  b = d;
  d = static_cast<Derived*>(b);
  delete d;

  Base base;
  Derived derived;
  Base& br = derived;
  Derived& dr = static_cast<Derived&>(br);
  

  return 0;
}
