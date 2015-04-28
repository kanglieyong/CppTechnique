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
  Node* current = NULL;
  while (pHead && *pHead) {
    current = *pHead;
    cout << "Destroy: " << current << ", " << current->value << endl;
    *pHead = (*pHead)->next;
    delete current;
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

  printListWithoutModify(head);
  cout << endl;

  Node* testNode = NULL;
  printListWithoutModify(testNode);
  cout << endl;
  
  destroyList(&head);
  
  return 0;
}
