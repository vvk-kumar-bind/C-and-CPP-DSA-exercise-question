#include <iostream>
#include <climits>
using namespace std;

struct Node
{
  int data;
  Node *next;
} *first;

// Node *first = nullptr;

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

void displayRecursive(Node *p)
{
  if (p != nullptr)
  {
    cout << p->data << " ";
    displayRecursive(p->next);
  }
}

void displayRecursiveReverse(Node *p)
{
  if (p != nullptr)
  {
    displayRecursiveReverse(p->next);
    cout << p->data << "  ";
  }
}

int countIterative(Node *p)
{
  int count = 0;
  while (p)
  {
    count++;
    p = p->next;
  }
  return count;
}

int countRecursive(Node *p)
{
  if (p == nullptr)
    return 0;
  return countRecursive(p->next) + 1;
}

int sumIterative(Node *p)
{
  int sum = 0;
  while (p != nullptr)
  {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int sumRecursive(Node *p)
{
  if (p == nullptr)
    return 0;
  return sumRecursive(p->next) + p->data;
}

int maxIterative(Node *p)
{
  int max = INT_MIN;
  while (p)
  {
    if (max < p->data)
      max = p->data;
    p = p->next;
  }
  return max;
}

int maxRecursive(Node *p)
{
  if (p == nullptr)
    return INT_MIN;
  int x = maxRecursive(p->next);
  return (x > p->data) ? x : p->data;
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

Node *searchRecursive(Node *p, int key)
{
  if (p == nullptr)
    return nullptr;
  if (key == p->data)
    return p;
  return searchRecursive(p->next, key);
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
    p = q;
    p = p->next;
  }
  return nullptr;
}

void Insert(int position, int x)
{
  Node *t, *p;

  if (position == 0)
  {
    t = new Node;
    t->data = x;
    t->next = first;
    first = t;
  }
  else if (position > 0)
  {
    p = first;
    for (int i = 0; i < position - 1 && p; i++)
      p = p->next;
    if (p)
    {
      t = new Node;
      t->data = x;
      t->next = p->next;
      p->next = t;
    }
  }
}

int main()
{
  int A[] = {10, 20, 40, 50, 60, 70, 80, 90};
  int sze = size(A);

  create(A, sze);

  displayIterative(first);

  Insert(0, 241);
  cout << endl
       << "Insert(0, 241)" << endl;
  displayRecursive(first);

  Insert(5, 234);
  cout << endl
       << "Insert(5, 234)" << endl;
  displayRecursive(first);
  Insert(sze, 236);
  cout << endl
       << "Insert(sze+1, 236)" << endl;
  displayIterative(first);

  return 0;
}