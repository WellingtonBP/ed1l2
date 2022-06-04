typedef struct _queue_node Node;
typedef struct _queue Queue;

Queue *create_queue();
int queue_empty(Queue *queue);
int queue_length(Queue *queue);
int enqueue(Queue *queue, void *data);
void *dequeue(Queue *queue);
void destroy_queue(Queue *queue);
void queue_for_each(Queue *queue, void (*fn)(void *));
