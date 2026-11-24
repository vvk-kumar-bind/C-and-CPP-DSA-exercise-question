#include <iostream>
using namespace std;

struct Term
{
  int coeff;
  int exp;
};

struct Polynomial
{
  int n;
  struct Term *term;
};

void create(struct Polynomial *p)
{
  printf("No. of non-zero terms");
  scanf("%d", &p->n);
  p->term = new Term[p->n];

  printf("Enter term \n");
  for (int i = 0; i < p->n; i++)
    scanf("%d%d", &p->term[i].coeff, &p->term[i].exp);
}

void display(struct Polynomial p)
{
  for (int i = 0; i < p.n; i++)
  {
    printf("%dx%d", p.term[i].coeff, p.term[i].exp);
    if (i < p.n - 1)
      printf(" + ");
  }

  printf("\n");
}

int main()
{
  struct Polynomial p1;
  create(&p1);
  display(p1);

  delete[] p1.term;

  return 0;
}
