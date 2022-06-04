typedef struct node Node;

typedef struct _list List;

void insert_node(List *mylist, void *data, int (*compareFn)(void *, void *));
void print_l(List mylist, void (*print_data)(void *));
List *create_list();