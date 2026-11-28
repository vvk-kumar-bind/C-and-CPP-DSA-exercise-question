#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};
Node *first = nullptr;
Node *last = nullptr;

void insertLast(int x)
{
  Node *t;
  t = new Node;
  t->data = x;
  t->next = nullptr;
  if (first == nullptr)
    first = last = t;
  else
  {
    last->next = t;
    last = t;
  }
}

void displayIterative(Node *p)
{
  while (p)
  {
    cout << p->data << "  ";
    p = p->next;
  }
}

void displayRecursive(Node *p)
{
  if (p)
  {
    cout << p->data << "  ";
    displayRecursive(p->next);
  }
}

void deleteList()
{
  Node *p = first;
  while (p != nullptr)
  {
    Node *temp = p;
    p = p->next;
    delete temp;
  }
  first = last = nullptr;
}

int main()
{
  int A[] = {10, 20, 40, 50, 60, 70, 80, 90};
  int sze = size(A);

  displayIterative(first);

  insertLast(241);
  cout << "After insertLast(241): ";
  displayRecursive(first);
  cout << endl;

  insertLast(234);
  cout << "After insertLast(234): ";
  displayRecursive(first);
  cout << endl;

  insertLast(236);
  cout << "After insertLast(236): ";
  displayIterative(first);

  deleteList();

  return 0;
}