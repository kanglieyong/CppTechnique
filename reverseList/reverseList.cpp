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
  Node* current = list;
  while (current != NULL) {
    cout << current->value << "->";
    current = current->next;
  }
  cout << "NULL" << endl;
}

int main(void)
{
  Node* head = NULL;
  Node* prev = NULL;
  Node* current;

  for (int i = 0; i < SIZE; i++) {
    current = new Node(i*i);
    current->next = NULL;

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
  cout << more << endl;
  printList(more);
  cout << "After reverse" << endl;
  more = reverseList(more);
  printList(more);

  cout << endl << "Destroy list: " << endl;
  while (head != NULL) {
    delete head;
    head = head->next;
  }
  if (head == NULL) cout << "head is NULL." << endl;

  return 0;
}
