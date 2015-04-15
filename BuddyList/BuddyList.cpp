#include "BuddyList.h"

using std::string;
using std::list;
void Buddylist::addBuddy(const string& name, const string& buddy)
{
  if (!isBuddy(name, buddy)) {
    mBuddies.insert({name, buddy});
  }
}

void BuddyList::removeBuddy(const string& name, const string& buddy)
{
  auto start = mBuddies.lower_bound(name);
  auto end = mBuddies.upper_bound(name);
  for (; start != end; ++start) {
    if (start->second == buddy) {
      mBuddies.erase(start);
      break;
    }
  }
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const
{
  auto start = mBuddies.lower_bound(name);
  auto end = mBuddies.upper_bound(name);
  for (; start != end; ++start) {
    if (start->second == buddy) return true;
  }
  return false;
}

list<string> BuddyList::getBuddies(const string& name) const
{
  auto its = mBuddies.equal_range(name);
  list<string> buddies;
  for (; its.first != its.second; ++its.first) buddies.push_back(its.first->second);
  return buddies;
}
