#include <stdlib.h>
#include "queue.h"

struct _queue_node
{
  void *dataPtr;
  struct _queue_node *link;
};

struct _queue
{
  Node *front;
  int count;
  Node *rear;
};

Queue *create_queue()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));

  queue->front = NULL;
  queue->rear = NULL;
  queue->count = 0;

  return queue;
}

int queue_empty(Queue *queue)
{
  return queue->count == 0;
}

int queue_length(Queue *queue)
{
  return queue->count;
}

int enqueue(Queue *queue, void *data)
{
  Node *node;

  if (!(node = (Node *)malloc(sizeof(Node))))
    return 0;

  node->dataPtr = data;
  node->link = NULL;

  if (!queue->front)
  {
    queue->front = node;
    queue->rear = node;
  }
  else
  {
    queue->rear->link = node;
    queue->rear = node;
  }

  queue->count++;

  return 1;
}

void *dequeue(Queue *queue)
{
  Node *front = queue->front;
  void *data = front->dataPtr;

  queue->front = front->link;
  free(front);

  queue->count--;

  return data;
}

void destroy_queue(Queue *queue)
{
  void *data;
  while (!queue_empty(queue))
  {
    data = dequeue(queue);
    free(data);
  }
  free(queue);
}

void queue_for_each(Queue *queue, void (*fn)(void *))
{
  Node *node = queue->front;

  while (node)
  {
    (*fn)(node->dataPtr);
    node = node->link;
  }
}