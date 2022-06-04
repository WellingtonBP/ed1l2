#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct node
{
  void *data;
  struct node *link;
};

struct _list
{
  int count;
  Node *first;
};

List *create_list()
{
  List *new = (List *)malloc(sizeof(List));
  new->count = 0;
  new->first = NULL;
  return new;
}

void insert_node(List *list, void *data, int (*compareFn)(void *, void *))
{
  int inserted = 0;

  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;

  if (!list->first)
  {
    list->first = node;
  }
  else
  {
    Node *current = list->first;
    Node *previews = NULL;
    while (!inserted)
    {
      if ((*compareFn)(current->data, node->data))
      {
        node->link = current;
        if (previews)
        {
          previews->link = node;
        }
        else
        {
          list->first = node;
        }
        inserted = 1;
      }
      else
      {
        previews = current;
        current = current->link;
        if (!current)
        {
          current = node;
          previews->link = current;
          inserted = 1;
        }
      }
    }
  }

  list->count++;
}

void print_l(List list, void (*print_fn)(void *))
{
  Node *elem = list.first;

  while (elem)
  {
    (*print_fn)(elem->data);
    elem = elem->link;
  }
}