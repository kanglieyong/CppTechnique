#include <iostream>

using std::cout;
using std::endl;

static const int SIZE = 10;

struct Node
{
  int value;
  Node* next;

  Node(int inValue)
    : value(inValue), next(NULL) {}
};

Node* reverseList(Node* plist)
{
  Node* pHead = NULL;
  Node* current = plist;
  Node* prev = NULL;

  while (current != NULL) {
    Node* pNext = current->next;
    if (pNext == NULL) pHead = current;
    current->next = prev;

    prev = current;
    current = pNext;
  }

  return pHead;
}

void printList(Node* plist)
{
  while (plist != NULL) {
    cout << plist->value << "->";
    plist = plist->next;
  }
  cout << "NULL" << endl;
}

int main(void)
{
  Node* head = NULL;
  Node* current;
  Node* prev;

  for (int i = 0; i < SIZE; i++) {
    current = new Node(i*i);
    current->next = NULL;

    if (head == NULL) {
      head = current;
    } else {
      prev->next = current;
    }
    // prev = prev->next;
    prev = current;
  }

  if (head == NULL) {
    cout << "NULL" << endl;
  }
  current = head;
  printList(current);

  head = reverseList(head);

  current = head;
  printList(head);

  return 0;
}
