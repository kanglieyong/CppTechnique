#include <iostream>

using std::cout;
using std::endl;

// Forward declaration
class Fish;
class Bear;
class Dinosaur;

//              Animal
//             /  |  \
//            /   |   \
//           /    |    \
//        Bear  Fish  Dinosaur

class Animal
{
public:
  virtual bool eats(const Animal& inPrey) const = 0;
  virtual bool eatenBy(const Bear& inBear) const = 0;
  virtual bool eatenBy(const Fish& inFish) const = 0;
  virtual bool eatenBy(const Dinosaur& inDinosaur) const = 0;
};

class Bear : public Animal
{
public:
  virtual bool eats(const Animal& inPrey) const;
  virtual bool eatenBy(const Bear& inBear) const;
  virtual bool eatenBy(const Fish& inFish) const;
  virtual bool eatenBy(const Dinosaur& inDinosaur) const;
};

class Fish : public Animal
{
public:
  virtual bool eats(const Animal& inPrey) const;
  virtual bool eatenBy(const Bear& inBear) const;
  virtual bool eatenBy(const Fish& inFish) const;
  virtual bool eatenBy(const Dinosaur& inDinosaur) const;
};

class Dinosaur : public Animal
{
public:
  virtual bool eats(const Animal& inPrey) const;
  virtual bool eatenBy(const Bear& inBear) const;
  virtual bool eatenBy(const Fish& inFish) const;
  virtual bool eatenBy(const Dinosaur& inDinosaur) const;
};

bool Bear::eats(const Animal& inPrey) const
{
  return inPrey.eatenBy(*this);
}

bool Bear::eatenBy(const Bear& inBear) const
{
  return false;
}

bool Bear::eatenBy(const Fish& inFish) const
{
  return false;
}

bool Bear::eatenBy(const Dinosaur& inDinosaur) const
{
  return true;
}


bool Fish::eats(const Animal& inPrey) const
{
  return inPrey.eatenBy(*this);
}

bool Fish::eatenBy(const Bear& inBear) const
{
  return true;
}

bool Fish::eatenBy(const Fish& inFish) const
{
  return true;
}

bool Fish::eatenBy(const Dinosaur& inDinosaur) const
{
  return true;
}


bool Dinosaur::eats(const Animal& inPrey) const
{
  return inPrey.eatenBy(*this);
}

bool Dinosaur::eatenBy(const Bear& inBear) const
{
  return false;
}

bool Dinosaur::eatenBy(const Fish& inFish) const
{
  return false;
}

bool Dinosaur::eatenBy(const Dinosaur& inDinosaur) const
{
  return true;
}

int main()
{
  Bear myBear;
  Fish myFish;
  Dinosaur myDinosaur;

  Animal& animalRef = myFish;
  cout << myBear.eats(animalRef) << endl;

  return 0;
}
