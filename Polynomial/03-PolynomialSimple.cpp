#include <iostream>
using namespace std;

struct Term
{
  int coeff;
  int exp;
};

class Polynomial
{
private:
  int n;
  Term *term;

public:
  Polynomial() : n(0), term(nullptr) {};

  ~Polynomial()
  {
    delete[] term;
  }

  void create()
  {
    cout << "No. of non-zcd ero terms: ";
    cin >> n;
    term = new Term[n];

    cout << "Enter terms(coeff exp):\n";
    for (int i = 0; i < n; i++)
    {
      cin >> term[i].coeff >> term[i].exp;
    }
  }

  void display()
  {
    cout << endl
         << "Polynomial : ";
    for (int i = 0; i < n; i++)
    {
      cout << term[i].coeff << "x^" << term[i].exp;
      if (i < n - 1)
      {
        if (i < n - 1)
        {
          cout << " + ";
        }
      }
    }
  }
};

int main()
{
  Polynomial p1;
  p1.create();
  p1.display();

  return 0;
}

/*
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
  ~Polynomial()
  {
    delete[] term;
  }

  void create(int n)
  {
    cout << "Number of non-zero: " << n << "\n";
    cout << "Enter Terms: ";
    for (int i = 0; i < n; i++)
    {
      cin >> term[i].coeff >> term[i].exp;
    }
  }

  void display()
  {
    cout << "\nPolynomial : ";
    bool *visited = new bool[n]{false}; // Tracks already combined terms
    bool first = true;

    for (int i = 0; i < n; i++)
    {
      if (visited[i])
        continue;

      int sumCoeff = term[i].coeff;

      // Look ahead for any remaining terms with the same exponent
      for (int j = i + 1; j < n; j++)
      {
        if (!visited[j] && term[j].exp == term[i].exp)
        {
          sumCoeff += term[j].coeff;
          visited[j] = true; // Mark as already added
        }
      }

      if (sumCoeff != 0)
      {
        if (!first)
          cout << " + ";
        cout << sumCoeff << "x^" << term[i].exp;
        first = false;
      }
    }

    if (first) // In case all terms canceled out to 0
      cout << "0";

    delete[] visited;
  }
};

int main()
{
  int n;
  cout << "Enter length of polynomial: ";
  cin >> n;
  Polynomial p(n);

  p.create(n);
  p.display();

  return 0;
}


*/