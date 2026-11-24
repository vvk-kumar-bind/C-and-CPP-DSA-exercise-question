#include <iostream>
using namespace std;

struct Term
{
  int coeff;
  int exp;
};

struct Poly
{
  int n;
  struct Term *term;
};

void create(struct Poly *p)
{
  cout << "Numbers of terms are ";
  cin >> p->n;
  p->term = new Term[p->n];
  cout << "Enter terms\n";
  for (int i = 0; i < p->n; i++)
  {
    cin >> p->term[i].coeff >> p->term[i].exp;
  }
}

void display(struct Poly p)
{
  for (int i = 0; i < p.n; i++)
  {
    cout << p.term[i].coeff << "x^" << p.term[i].exp;
    if (i < p.n - 1)
      cout << " + ";
  }
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
  struct Poly *sum;
  sum = (struct Poly *)malloc(sizeof(struct Poly));
  sum->term = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

  int i, j, k;
  i = j = k = 0;

  while (i < p1->n && j < p2->n)
  {
    if (p1->term[i].exp < p2->term[j].exp)
    {
      sum->term[k++] = p2->term[j++];
    }
    else if (p1->term[i].exp > p2->term[j].exp)
    {
      sum->term[k++] = p1->term[i++];
    }
    else
    {
      sum->term[k].exp = p1->term[i].exp;
      sum->term[k++].coeff = p1->term[i].coeff + p2->term[j].coeff;
    }
  }
  for (; i < p1->n; i++)
  {
    sum->term[k++] = p1->term[i];
  }
  for (; j < p2->n; j++)
  {
    sum->term[k++] = p2->term[j];
  }
  sum->n = k;
  return sum;
}

int main()
{
  struct Poly p1, p2, *p3;
  create(&p1);
  create(&p2);
  p3 = add(&p1, &p2);
  cout << endl;
  display(p1);
  cout << endl;
  display(p2);
  cout << endl;
  display(*p3);

  return 0;
}