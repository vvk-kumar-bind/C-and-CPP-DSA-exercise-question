#include <iostream>
using namespace std;

class Toeplitz
{
  int n;
  int *A;

public:
  Toeplitz(int n);
  ~Toeplitz();
  void setToeplitz(int i, int j, int x);
  int getToeplitz(int i, int j);
  void display();
};

Toeplitz::Toeplitz(int n)
{
  this->n = n;
  A = new int[2 * n - 1];
}

Toeplitz::~Toeplitz()
{
  delete[] A;
}

void Toeplitz::setToeplitz(int i, int j, int x)
{
  if (i <= j)
    A[j - i] = x;
  else // if(i>j)
  {
    A[n + i - j - 1] = x;
  }
}

int Toeplitz::getToeplitz(int i, int j)
{
  if (i <= j)
    return A[j - i];
  // else return A[n+i-j];
  return A[n + i - j - 1];
}

void Toeplitz::display()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << getToeplitz(i, j) << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n = 5;
  Toeplitz t(n);
  int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int index = 0;

  for (int j = 1; j <= n; j++)
  {
    t.setToeplitz(1, j, A[index++]);
  }
  for (int i = 2; i <= n; i++)
  {
    t.setToeplitz(i, 1, A[index++]);
  }

  t.display();

  return 0;
}