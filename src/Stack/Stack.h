typedef struct Stack Stack; 

Stack * init_stack(size_t type);
void free_stack(Stack * s); 
void push(Stack * s, void * data);
void * pop(Stack * s); 
void * stack_peek(Stack * s); 
int contains(Stack * s, void * data, int (* compare)(void *, void *));
int stack_is_empty(Stack * s);  
