#include <queue>
#include <stdexcept>
#include <memory>

using std::queue;
using std::shared_ptr;

template <typename T>
class ObjectPool
{
 public:
  ObjectPool(size_t chunkSize = kDefaultChunkSize)
    throw (std::invalid_argument, std::bad_alloc);

  shared_ptr<T> acquireObject();
  void releaseObject(shared_ptr<T> obj);
  
 protected:
  queue<shared_ptr<T>> mFreeList;
  size_t mChunkSize;
  
  static const size_t kDefaultChunkSize = 10;
  
  void allocateChunk();
  
 private:
  ObjectPool(const ObjectPool<T>& src);
  ObjectPool<T>& operator=(const ObjectPool<T>& rhs);
};

template <typename T>
ObjectPool<T>::ObjectPool(size_t chunkSize) throw(std::invalid_argument, std::bad_alloc)
{
  if (chunkSize == 0) {
    throw std::invalid_argument("chunk size  must be positive");
  }
  mChunkSize = chunkSize;
  allocateChunk();
}

template <typename T>
void ObjectPool<T>::allocateChunk()
{
  for (size_t i = 0; i < mChunkSize; i++) {
    mFreeList.push(std::make_shared<T>());
  }
}

template <typename T>
shared_ptr<T> ObjectPool<T>::acquireObject()
{
  if (mFreeList.empty()) {
    allocateChunk();
  }
  auto obj = mFreeList.front();
  mFreeList.pop();
  return obj;
}

template <typename T>
void ObjectPool<T>::releaseObject(shared_ptr<T> obj)
{
  mFreeList.push(obj);
}
