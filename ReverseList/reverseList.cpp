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

Node* reverseList(Node* pRoot)
{
  Node* rHead = NULL;
  Node* current = pRoot;
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
  Node* current = list;
  while (current != NULL) {
    cout << current->value << "->";
    current = current->next;
  }
  cout << "NULL" << endl;
}

void destroyList(Node** plist)
{
  while (plist && *plist) {
    cout << *plist << ", value = " << (*plist)->value << endl;
    delete *plist;
    *plist = (*plist)->next;
  }
}

int main(void)
{
  Node* head = NULL;
  Node* prev = NULL;
  Node* current;

  for (int i = 0; i < SIZE; i++) {
    current = new Node(i*i);

    if (head == NULL) head = current;
    else        prev->next = current;

    prev = current;
  }

  if (head == NULL) {
    cout << "NULL" << endl;
  }
  cout << "Test head" << endl;
  printList(head);

  cout << "After reverse" << endl;
  head = reverseList(head);
  printList(head);
  cout << endl;

  Node* testNode = NULL;
  cout << "Test NULL" << endl;
  printList(testNode);
  testNode = reverseList(testNode);
  cout << "After reverse" << endl;
  printList(testNode);
  cout << endl;

  Node* more = new Node(10);
  cout << "Test 1 element" << endl;
  cout << "Address: " << more << endl;
  printList(more);
  cout << "After reverse" << endl;
  more = reverseList(more);
  printList(more);
  cout << endl; 
  destroyList(&more);
  cout << endl;

  destroyList(&head);

  if (head == NULL) cout << "head is NULL." << endl;

  return 0;
}
