#include <stdio.h>
#include <stdlib.h>
#include "adt/linked_list.h"

typedef struct
{
  int coefficient;
  int exponent;
} Monomial;

int compare(Monomial *m1, Monomial *m2)
{
  return m1->exponent > m2->exponent;
}

Monomial *create_monomial(int coefficient, int exponent)
{
  Monomial *new = (Monomial *)malloc(sizeof(Monomial));
  new->coefficient = coefficient;
  new->exponent = exponent;
  return new;
}

void printfn(Monomial *monomial)
{
  printf("%ix^%i + ", monomial->coefficient, monomial->exponent);
}

List *calc(List *fistp, List *secondp) {}

int main()
{
  List *firstp = create_list();
  List *secondp = create_list();

  insert_node(firstp, create_monomial(5, 4), &compare);
  insert_node(firstp, create_monomial(6, 3), &compare);
  insert_node(firstp, create_monomial(7, 0), &compare);
  insert_node(secondp, create_monomial(2, 3), &compare);
  insert_node(secondp, create_monomial(7, 2), &compare);
  insert_node(secondp, create_monomial(3, 1), &compare);

  List *result = calc(firstp, secondp);

  printfn(firstp);
  printf("\n");
  printfn(secondp);
  printf("\n");
  printfn(firstp);
  printf("\n");
}