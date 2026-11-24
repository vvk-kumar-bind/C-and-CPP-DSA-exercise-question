#include <iostream>
using namespace std;

struct Term
{
  int coeff;
  int exp;
};

class Polynomial
{
  int n;
  Term *term;

public:
  Polynomial(int n)
  {
    this->n = n;
    term = new Term[n];
  }

  // Copy constructor to prevent double-free crashes
  Polynomial(Polynomial &other)
  {
    n = other.n;
    term = new Term[n];
    for (int i = 0; i < n; i++)
    {
      term[i] = other.term[i];
    }
  }

  ~Polynomial()
  {
    delete[] term;
  }

  void create(int n)
  {
    cout << "Number of non-zero: " << n << "\n";
    cout << "Enter Terms (coeff exp):\n";
    for (int i = 0; i < n; i++)
    {
      cin >> term[i].coeff >> term[i].exp;
    }
  }

  void display()
  {
    cout << "\nPolynomial : ";
    for (int i = 0; i < n; i++)
    {
      cout << term[i].coeff << "x^" << term[i].exp;
      if (i < n - 1)
        cout << " + ";
    }
    cout << "\n";
  }

  friend Polynomial add(Polynomial &p1, Polynomial &p2);
};

Polynomial add(Polynomial &p1, Polynomial &p2)
{
  int i = 0, j = 0, k = 0;
  Polynomial sum(p1.n + p2.n);

  while (i < p1.n && j < p2.n)
  {
    if (p1.term[i].exp > p2.term[j].exp)
    {
      sum.term[k++] = p1.term[i++];
    }
    else if (p1.term[i].exp < p2.term[j].exp)
    {
      sum.term[k++] = p2.term[j++];
    }
    else
    {
      sum.term[k].exp = p1.term[i].exp;
      sum.term[k++].coeff = p1.term[i++].coeff + p2.term[j++].coeff;
    }
  }

  while (i < p1.n)
  {
    sum.term[k++] = p1.term[i++];
  }

  while (j < p2.n)
  {
    sum.term[k++] = p2.term[j++];
  }

  sum.n = k;
  return sum;
}

int main()
{
  int n1, n2;

  cout << "Enter length of 1st polynomial: ";
  cin >> n1;
  Polynomial p1(n1);
  p1.create(n1);

  cout << "\nEnter length of 2nd polynomial: ";
  cin >> n2;
  Polynomial p2(n2);
  p2.create(n2);

  Polynomial p3 = add(p1, p2);

  p1.display();
  p2.display();
  p3.display();

  return 0;
}
