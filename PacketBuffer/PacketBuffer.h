#include <queue>
#include <stdexcept>

template <typename T>
class PacketBuffer
{
 public:
  PacketBuffer(size_t maxSize = 0);

  bool bufferPacket(const T& packet);
  T getNextPacket() throw (std::out_of_range);
  
 private:
  std::queue<T> mPackets;
  int mMaxSize;
};

template <typename T>
PacketBuffer<T>::PacketBuffer(size_t maxSize)
: mMaxSize(maxSize)
{}

template <typename T>
bool PacketBuffer<T>::bufferPacket(const T& packet)
{
  if (mMaxSize > 0 && mPackets.size() == mMaxSize) return false;
  
  mPackets.push(packet);
  return true;
}

template <typename T>
T PacketBuffer<T>::getNextPacket() throw (std::out_of_range)
{
  if (mPackets.empty()) throw std::out_of_range("Buffer is empty");
  
  T temp = mPackets.front();
  mPackets.pop();
  return temp;
}
