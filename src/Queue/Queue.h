typedef struct Queue Queue; 

Queue * init_queue(size_t type); 
void free_queue(Queue * q); 
void enqueue(Queue * q, void * data); 
void * dequeue(Queue * q); 
void * queue_peek(Queue * q); 
int queue_is_empty(Queue * q); 
int queue_contains(Queue * q, void * data, int (* compare)(void *, void *)); 
int queue_len(Queue * q); 
void * queue_to_array(Queue * q); 