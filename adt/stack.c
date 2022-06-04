#include <stdlib.h>
#include "stack.h"

struct _stack_node
{
  void *dataPtr;
  struct _stack_node *link;
};

struct _stack
{
  int count;
  Node *top;
};

Stack *new_stack()
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->count = 0;
  stack->top = NULL;

  return stack;
}

int push_stack(Stack *stack, void *data)
{
  Node *node;

  if (!(node = (Node *)malloc(sizeof(Node))))
  {
    return 0;
  }

  node->dataPtr = data;
  node->link = stack->top;
  stack->top = node;
  stack->count++;

  return 1;
}

void *pop_stack(Stack *stack)
{
  Node *top = stack->top;
  void *data = top->dataPtr;

  stack->top = top->link;
  stack->count--;
  free(top);
  return data;
}

int empty_stack(Stack *stack)
{
  return stack->count == 0;
}

void *top_stack(Stack *stack)
{
  return stack->top->dataPtr;
}

void print_stack(Stack *stack, void (*printFn)(void *))
{
  Node *aux = stack->top;

  while (aux)
  {
    (*printFn)(aux->dataPtr);
    aux = aux->link;
  }
}

void invert_stack(Stack **stack)
{
  Stack *aux = new_stack();

  while (!empty_stack(*stack))
  {
    push_stack(aux, pop_stack(*stack));
  }
  *stack = aux;
}

int size_stack(Stack *stack)
{
  return stack->count;
}