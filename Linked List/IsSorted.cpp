#include <iostream>
#include <climits>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *first = nullptr;

void create(int A[], int size)
{
  if (size <= 0)
    return;
  Node *t, *last;
  first = new Node;
  first->data = A[0];
  first->next = nullptr;
  last = first;

  for (int i = 1; i < size; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = nullptr;
    last->next = t;
    last = t;
  }
}

void displayIterative(Node *p)
{
  while (p != nullptr)
  {
    cout << p->data << " ";
    p = p->next;
  }
}

Node *searchRecursive(Node *p, int key)
{
  if (p == nullptr)
    return nullptr;
  if (key == p->data)
    return p;
  return searchRecursive(p->next, key);
}

Node *searchIterative(Node *p, int key)
{
  while (p != nullptr)
  {
    if (key == p->data)
      return p;
    p = p->next;
  }
  return nullptr;
}

Node *improveSearch(Node *p, int key)
{
  Node *q = nullptr;
  while (p != nullptr)
  {
    if (key == p->data)
    {
      if (q != nullptr)
      {
        q->next = p->next;
        p->next = first;
        first = p;
      }
      return first;
    }
    q = p;
    p = p->next;
  }
  return nullptr;
}

void Insert(int position, int x)
{
  if (position < 0)
    return;
  Node *t, *p;
  t = new Node;
  t->data = x;
  if (position == 0)
  {
    t->next = first;
    first = t;
  }
  // else if (position > 0)
  else
  {
    p = first;
    for (int i = 0; i < position - 1 && p; i++)
      p = p->next;
    if (p)
    {
      t->next = p->next;
      p->next = t;
    }
    else
    {
      delete t;
    }
  }
}

bool isSorted(Node *p)
{
  int x = INT_MIN;
  while (p)
  {
    if (p->data < x)
      return false;
    x = p->data;
    p = p->next;
  }
  return true;
}

int main()
{
  int A[] = {10, 20, 40, 50, 60, 70, 80, 90};
  int sze = size(A);

  // create(A, sze);
  cout << isSorted(first);

  return 0;
}