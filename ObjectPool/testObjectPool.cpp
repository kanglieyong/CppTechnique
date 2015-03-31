#include "ObjectPool.h"
#include "UserRequest.h"
#include <iostream>
using std::cout;
using std::endl;

shared_ptr<UserRequest> obtainUserRequest(ObjectPool<UserRequest>& pool)
{
  auto request = pool.acquireObject();
  return request;
}

void processUserRequest(ObjectPool<UserRequest>& pool, shared_ptr<UserRequest> req)
{
  pool.releaseObject(req);
}

int main()
{
  ObjectPool<UserRequest> requestPool(10);
  cout << "Loop starting." << endl;
  for (size_t i = 0; i < 100; i++) {
    auto req = obtainUserRequest(requestPool);
    processUserRequest(requestPool, req);
  }
  cout << "Loop finished." << endl;
}
