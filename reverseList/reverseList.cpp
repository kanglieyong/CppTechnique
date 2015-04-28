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

Node* reverseList2(Node* plist)
{
  Node* rHead = NULL;
  Node* current = plist;  
  Node* tmp;

  while (current != NULL) {
    tmp = current->next;
    current->next = rHead;
    
    rHead = current;
    current = tmp;
  }
  return rHead;
}


void printList(Node* list)
{
  while (list != NULL) {
    cout << list->value << "->";
    list = list->next;
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

  current = head;
  current = reverseList2(current);
  printList(current);

  cout << endl;

  Node* testNode = NULL;
  printList(testNode);
  testNode = reverseList2(testNode);
  printList(testNode);

  cout << endl;

  Node* more = new Node(10);
  cout << more << endl;
  printList(more);
  cout << more << endl;
  more = reverseList2(more);
  printList(more);

  cout << endl << "Destroy list: " << endl;
  while (head != NULL) {
    delete head;
    head = head->next;
  }
  if (head == NULL) cout << "head is NULL." << endl;

  return 0;
}
