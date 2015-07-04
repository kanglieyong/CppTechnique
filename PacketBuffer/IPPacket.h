class IPPacket
{
 public:
  IPPacket(int id)
    : mID(id)
  {}

  int getID() const
  {
    return mID;
  }

 private:
  int mID;
};
