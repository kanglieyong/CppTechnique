#include <iostream>

using std::cout;
using std::endl;

struct ListNode
{
  int value;
  ListNode* next;

  ListNode(int inValue)
    : value(inValue), next(0) {}
};

void printListNode(ListNode* plist)
{
  while (plist->next != NULL) {
    cout << plist->value << "->";
    plist = plist->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  ListNode* pHead = new ListNode(0);
  ListNode* cur = pHead;
  for (int i = 1; i < 5; i++) {
    ListNode* newnode = new ListNode(i); 
    cur->next = newnode;
    cur = cur->next;
  }
  printListNode(pHead);

  return 0;
}
