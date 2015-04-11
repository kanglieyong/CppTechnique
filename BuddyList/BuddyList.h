#include <string>
#include <list>
#include <map>

class BuddyList
{
 public:
  BuddyList();

  void addBuddy(const std::string& name, const std::string& buddy);
  void removeBuddy(const std::string& name, const std::string& buddy);
  bool isBuddy(const std::string& name, const std::string& buddy) const;
  std::list<std::string> getBuddies(const std::string& name) const;
  
 protected:
  std::multimap<std::string, std::string> mBuddies;
};
