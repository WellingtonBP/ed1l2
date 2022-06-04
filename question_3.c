#include <stdio.h>
#include <stdlib.h>
#include "adt/queue.h"

void cat(Queue *first, Queue *second)
{
  void do_cat(void *data)
  {
    enqueue(first, data);
  };

  queue_for_each(second, &do_cat);
}

void cat_delete(Queue *first, Queue *second)
{
  while (!queue_empty(second))
  {
    enqueue(first, dequeue(second));
  }
}

int main()
{
  Queue *first = create_queue();
  Queue *second = create_queue();
  int *first_i, *second_i, i;

  for (i = 1; i < 11; i++)
  {
    first_i = malloc(sizeof(int));
    second_i = malloc(sizeof(int));

    *first_i = i;
    *second_i = i + 10;

    enqueue(first, first_i);
    enqueue(second, second_i);
  }

  cat(first, second);
  cat_delete(first, second);

  while (!queue_empty(first))
  {
    printf("%i ", *((int *)dequeue(first)));
  }

  return 0;
}