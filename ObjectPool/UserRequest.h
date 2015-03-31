#include <iostream>

class UserRequest
{
 public:
  UserRequest() { id = sId++; std::cout << "this ID = " << id << std::endl; }
  virtual ~UserRequest() {sId--; }
  int getID() { return id; }

 protected:
  static int sId;
  int id;
};

int UserRequest::sId = 0;
