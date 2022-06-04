typedef struct _stack_node Node;
typedef struct _stack Stack;

Stack *new_stack();
int push_stack(Stack *stack, void *data);
void *pop_stack(Stack *stack);
void *top_stack(Stack *stack);
void print_stack(Stack *, void (*printFn)(void *));
int empty_stack(Stack *stack);
void invert_stack(Stack **stack);
int size_stack(Stack *stack);