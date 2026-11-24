#include <iostream>
using namespace std;

class Term
{
public:
  int coeff;
  int exp;
};

class Polynomial
{
public:
  int n;
  Term *term;

  Polynomial(int n);
  ~Polynomial();
  friend istream &operator>>(istream &is, Polynomial &p);
  friend ostream &operator<<(ostream &os, Polynomial &p);
};

Polynomial::Polynomial(int n)
{
  this->n = n;
  term = new Term[n];
}

Polynomial::~Polynomial()
{
  delete[] term;
}

istream &operator>>(istream &is, Polynomial &p)
{
  cout << "Enter " << p.n << " non-zero terms (coefficient) are";
  for (int i = 0; i < p.n; i++)
  {
    cout << "Term " << i + 1 << ": ";
    is >> p.term[i].coeff >> p.term[i].exp;
  }
  return is;
}

ostream &operator<<(ostream &os, Polynomial &p)
{
  for (int i = 0; i < p.n; i++)
  {
    os << p.term[i].coeff << "x^" << p.term[i].exp;
    if (i < p.n - 1)
      os << " + ";
  }
  os << endl;
  return os;
}

int main()
{
  int count;
  cout << "Enter number of non-zero terms: ";
  cin >> count;

  Polynomial p(count);
  cin >> p;
  cout << endl
       << "Polynomial: ";
  cout << p;

  return 0;
}