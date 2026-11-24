#include <iostream>
using namespace std;

class Tridiagonal
{
  int n;
  int *A;

public:
  Tridiagonal(int n);
  ~Tridiagonal();
  void setTridiagonal(int i, int j, int x);
  int getTridiagonal(int i, int j);
  void display();
};

Tridiagonal::Tridiagonal(int n)
{
  this->n = n;
  A = new int[3 * n - 2];
}

Tridiagonal::~Tridiagonal()
{
  delete[] A;
}

void Tridiagonal::setTridiagonal(int i, int j, int x)
{
  if (i - j == 1)
  {
    A[i - 2] = x;
  }
  else if (i - j == 0)
  {
    A[n - 1 + i - 1] = x;
  }
  else if (i - j == -1)
  {
    A[2 * n - 1 + i - 1] = x;
  }
}

int Tridiagonal::getTridiagonal(int i, int j)
{
  if (i - j == 1)
    return A[i - 2];
  else if (i - j == 0)
    return A[n + i - 2];
  else if (i - j == -1)
    return A[2 * n + i - 2];
  else
    return 0;
}

void Tridiagonal::display()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (abs(i - j) <= 1)
        cout << getTridiagonal(i, j) << " ";
      else
        cout << 0 << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n = 5, x;
  Tridiagonal T(n);
  int A[] = {1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 2, 3, 4};
  int index = 0;

  for (int i = 2; i <= n; i++)
  {

    T.setTridiagonal(i, i - 1, A[index++]);
  }
  for (int i = 1; i <= n; i++)
  {

    T.setTridiagonal(i, i, A[index++]);
  }
  for (int i = 1; i <= n - 1; i++)
  {

    T.setTridiagonal(i, i + 1, A[index++]);
  }
  T.display();
  return 0;
}
