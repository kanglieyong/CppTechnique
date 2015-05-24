#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

static const int SIZE = 10;
struct Node {
  int value;
  Node* next;

  Node(int inValue)
    : value(inValue), next(NULL) {}
};

void printList(Node* head)
{
  Node* current = head;
  while (current != NULL) {
    cout << current << ", " << current->value << endl;
    current = current->next;
  }
}

void destroyList(Node** pHead)
{
  while (pHead && *pHead) {
    cout << "Destroy: " << *pHead << ", " << (*pHead)->value << endl;
    delete *pHead;
    *pHead = (*pHead)->next;
  }
  
}

void printListWithoutModify(Node* head)
{
  std::stack<Node*> nodes;
  Node* pnode = head;

  while (pnode != NULL) {
    nodes.push(pnode);
    pnode = pnode->next;
  }

  while (!nodes.empty()) {
    pnode = nodes.top();
    cout << pnode << ", " << pnode->value << endl;
    nodes.pop();
  }
}
void printListByRecurse(Node* head)
{
  if (head != NULL) {
    if (head->next != NULL) {
      printListByRecurse(head->next);
    }
    cout << head << ", " << head->value << endl;
  }
}

int main(void)
{
  Node* head = NULL;
  Node* prev;
  Node* current;

  for (int i = 0; i < SIZE; i++) {
    current = new Node(i*i);

    if (head == NULL) head = current;
    else        prev->next = current;

    prev = current;
  }

  printList(head);
  cout << endl;

  cout << "Loop version:" << endl;
  printListWithoutModify(head);
  cout << endl;

  cout << "Recurse version:" << endl;
  printListByRecurse(head);
  cout << endl;

  Node* testNode = NULL;
  printListWithoutModify(testNode);
  
  destroyList(&head);

  cout << endl;
  
  return 0;
}
