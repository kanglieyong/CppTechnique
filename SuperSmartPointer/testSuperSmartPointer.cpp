#include "SuperSmartPointer.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Nothing
{
public:
  Nothing() { sNumAllocations++; }
  virtual ~Nothing() { sNumDeletions++; }

  static int sNumAllocations;
  static int sNumDeletions;
};

int Nothing::sNumAllocations;
int Nothing::sNumDeletions;

int main(void)
{
  Nothing* myNothing = new Nothing();
  {
    SuperSmartPointer<Nothing> ptr1(myNothing);
    SuperSmartPointer<Nothing> ptr2(myNothing);
  }

  if (Nothing::sNumAllocations != Nothing::sNumDeletions) {
    cout << "TEST FAILED: " << Nothing::sNumAllocations << " allocations and " << Nothing::sNumDeletions << " deletions" << endl;
  } else {
    cout << "TEST PASSED" << endl;
  }

  {
    SuperSmartPointer<string> ptr3(new string("Hello, World!"));
    SuperSmartPointer<string> ptr4(ptr3);
    if (*ptr3 == *ptr4) cout << "TEST PASSED" << endl;
  }

  {
    SuperSmartPointer<string> ptr5(new string("Dennis Ritchie"));
    SuperSmartPointer<string> ptr6(new string("John Donne"));
    ptr6 = ptr5;
    if (*ptr5 == *ptr6) cout << "Test PASSED" << endl;
    cout << "*ptr5 = " << *ptr5 << ", *ptr6 = " << *ptr6 << endl;
    cout << "ptr5 = " << ptr5 << ", ptr6 = " << ptr6 << endl;
  }

  return 0;
}
