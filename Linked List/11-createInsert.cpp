#include <iostream>
#include <climits>
using namespace std;

struct Node
{
  int data;
  Node *next;
}; //*first;

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
  while (p != NULL)
  {
    cout << p->data << "  ";
    p = p->next;
  }
}

void displayRecursive(Node *p)
{
  if (p != NULL)
  {
    cout << p->data << "  ";
    displayRecursive(p->next);
  }
}

void displayRecursiveRecerse(Node *p)
{
  if (p != nullptr)
  {
    displayRecursiveRecerse(p->next);
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
  if (!p)
    return 0;
  return countRecursive(p->next) + 1;
}

int sumIterative(Node *p)
{
  int sum = 0;
  while (p)
  {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int sumRecursive(Node *p)
{
  if (!p)
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
  if (!p)
    return INT_MIN;
  int x = maxRecursive(p->next);
  return (x > p->data) ? x : p->data;
}

Node *searchIterative(Node *p, int key)
{
  while (p)
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
  if (p->data == key)
    return p;
  return searchRecursive(p->next, key);
}

Node *searchImprove(Node *p, int key)
{
  Node *q = nullptr;
  while (p)
  {
    if (p->data == key)
    {
      if (q)
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

void insert(int position, int x)
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
  else if (position > 0)
  {
    p = first;
    for (int i = 0; i < position - 1; i++)
      p = p->next;
    if (p != nullptr)
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

void deleteList()
{
  Node *p = first;
  while (p != nullptr)
  {
    Node *temp = p;
    p = p->next;
    delete temp;
  }
  first = nullptr;
}

int main()
{
  insert(0, 8);
  displayIterative(first);
  cout << endl;
  insert(1, 2);
  displayIterative(first);
  cout << endl;
  insert(2, 348);
  displayIterative(first);
  cout << endl;
  insert(3, 3);
  displayIterative(first);
  cout << endl;
  insert(4, 28);
  displayIterative(first);
  cout << endl;

  deleteList();
  return 0;
}