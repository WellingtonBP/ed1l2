#include <stdlib.h>
#include <stdio.h>
#include "adt/stack.h"

int *number(int number)
{
  int *aux = (int *)malloc(sizeof(int));

  *aux = number;
  return aux;
}

char *hex_number(int number)
{
  char helper[6] = "ABCDEF";
  char *aux = (char *)malloc(sizeof(char));

  *aux = helper[number - 10];
  return aux;
}

void fill_stack(Stack *stack, int decimal_number)
{
  int rest;

  while (decimal_number)
  {
    rest = decimal_number % 16;
    if (rest > 9)
      push_stack(stack, hex_number(rest));
    else
      push_stack(stack, number(rest));
    decimal_number /= 16;
  }
}

void printdata(void *data)
{
  if (*((int *)data) < 10)
    printf("%i", *((int *)data));
  else
    printf("%c", *((char *)data));
}

int main()
{
  Stack *stack = new_stack();
  void *printFn = &printdata;
  int decimal_number;

  printf("Enter decimal number: ");
  scanf("%i", &decimal_number);

  fill_stack(stack, decimal_number);

  print_stack(stack, printFn);
  return 0;
}