#include "BuddyList.h"

using std::string;

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
