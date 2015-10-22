#include <iostream>

using std::cout;
using std::endl;

// forward declaration
class Fish;
class Bear;
class Dinosaur;

//                                    Animal
//                                  /   |   \
//                                 /    |    \
//                                /     |     \
//                             Fish    Bear   Dinosaur

class Animal
{
  public:
    virtual bool eats(const Bear& inPrey) const = 0;
    virtual bool eats(const Fish& inPrey) const = 0;
    virtual bool eats(const Dinosaur& inPrey) const = 0;
};

class Fish : public Animal
{
  public:
    virtual bool eats(const Bear& inPrey) const
    {
      return false;
    }

    virtual bool eats(const Fish& inPrey) const
    {
      return true;
    }

    virtual bool eats(const Dinosaur& inPrey) const
    {
      return false;
    }
};

class Bear : public Animal
{
  public:
    virtual bool eats(const Bear& inPrey) const
    {
      return false;
    }

    virtual bool eats(const Fish& inPrey) const
    {
      return true;
    }

    virtual bool eats(const Dinosaur& inPrey) const
    {
      return false;
    }
};

class Dinosaur : public Animal
{
  public:
    virtual bool eats(const Bear& inPrey) const
    {
      return true;
    }

    virtual bool eats(const Fish& inPrey) const
    {
      return true;
    }

    virtual bool eats(const Dinosaur& inPrey) const
    {
      return true;
    }
};

int main()
{
  Fish myFish;
  Bear myBear;
  Dinosaur myDinosaur;

  cout << "Fish eats Fish " << myFish.eats(myFish) << endl;
  cout << "Fish eats Bear " << myFish.eats(myBear) << endl;
  cout << "Fish eats Dinosaur " << myFish.eats(myDinosaur) << endl;
  cout << endl;

  cout << "Bear eats Fish " << myBear.eats(myFish) << endl;
  cout << "Bear eats Bear " << myBear.eats(myBear) << endl;
  cout << "Bear eats Dinosaur " << myBear.eats(myDinosaur) << endl;
  cout << endl;

  cout << "Dinosaur eats Fish " << myDinosaur.eats(myFish) << endl;
  cout << "Dinosaur eats Bear " << myDinosaur.eats(myBear) << endl;
  cout << "Dinosaur eats Dinosaur " << myDinosaur.eats(myDinosaur) << endl;
  cout << endl;

  //-----PASS
  Bear bear;
  Fish fish;
  Animal& animalRef = bear;
  cout << animalRef.eats(fish) << endl;

  //---- FAILURE
  // Bear anotherBear;
  // Fish anotherFish;
  // Animal& anotherAnimalRef = anotherFish;
  // cout << anotherBear.eats(anotherAnimalRef) << endl;

  return 0;
}
