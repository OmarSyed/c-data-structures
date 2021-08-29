#include <stdlib.h>
#include "Stack.h"
#include "../LinkedList/SinglyLinkedList.h"

struct Stack
{
    SList * list; 
};

Stack * init_stack(size_t type)
{
    Stack * stack = calloc(1, sizeof(Stack)); 
    stack->list = init_sll(type); 
}

void free_stack(Stack * s)
{
    free_sll(s->list); 
    free(s); 
} 

void push(Stack * s, void * data)
{
    sll_add(s->list, data); 
}

void * pop(Stack * s)
{
    void * data = sll_get(s->list, sll_len(s->list)- 1); 
    sll_delete(s->list, sll_len(s->list) - 1); 
    return data; 
}

void * stack_peek(Stack * s)
{
    return sll_get(s->list, sll_len(s->list) - 1); 
} 

int contains(Stack * s, void * data, int (* compare)(void *, void *))
{
    return sll_contains(s->list, data, compare); 
}

int stack_is_empty(Stack * s)
{
    return sll_is_empty(s->list);
}
