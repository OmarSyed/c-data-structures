#include <stdlib.h>
#include "Queue.h"
#include "../LinkedList/SinglyLinkedList.h"

struct Queue
{
    SList * list; 
};

Queue * init_queue(size_t type)
{
    Queue * newQ = calloc(1, sizeof(Queue)); 
    newQ->list = init_sll(type); 
} 

void free_queue(Queue * q)
{
    free_sll(q->list); 
    free(q); 
}

void enqueue(Queue * q, void * data)
{
    sll_add(q->list, data); 
}

void * dequeue(Queue * q)
{
    void * ptr = sll_get(q->list, 0); 
    sll_delete(q->list, 0); 
    return ptr; 
} 

void * queue_peek(Queue * q)
{
    return sll_get(q->list, 0); 
}

int queue_is_empty(Queue * q)
{
    return sll_is_empty(q->list); 
} 

int queue_contains(Queue * q, void * data, int (* compare)(void *, void *))
{
    return sll_contains(q->list, data, compare); 
} 

int queue_len(Queue * q)
{
    return sll_len(q->list); 
}

void * queue_to_array(Queue * q)
{
    char * array = calloc(queue_len(q), sll_type(q->list));
    int i = 0; 
    while (queue_is_empty(q) == 0)
    {
        array[i] = dequeue(q);
        i += sll_type(q->list);  
    } 
    return array; 
}