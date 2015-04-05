#include "AccessList.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  AccessList fileX = {"Scolett", "Kang", "Rhett"};
  fileX.removeUser("Scolett");
  if (fileX.isAllowed("Scolett")) {
    cout << "Scolett has permissions" << endl;
  }

  if (fileX.isAllowed("Rhett")) {
    cout << "Rhett has permisions" << endl;
  }
  auto users = fileX.getAllUsers();
  for (auto & user : users) {
    cout << user << " ";
  }
  cout << endl;
  
  return 0;
}
