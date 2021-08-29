#include "SinglyLinkedList.h"
#include <stdlib.h>

typedef struct SinglyLinkedNode
{
    void * data; 
    SNode * next; 
} SNode;

struct SinglyLinkedList
{
    SNode * head; 
    SNode * tail;
    size_t elementSize; 
    int len;  
}; 

SList * init_sll(size_t type)
{
    SList * newList = calloc(1, sizeof(SList)); 
    newList->head = NULL; 
    newList->tail = NULL; 
    newList->elementSize = type; 
    newList->len = 0; 
    return newList; 
}

void free_sll(SList * list)
{   
    while (!sll_is_empty(list))
    {
        sll_delete(list, 0); 
    }
    free(list); 
}

void sll_add(SList * list, void * data)
{
    SNode * ptr = list->head, * prev = NULL, * newNode; 
    while (ptr != NULL)
    {
        prev = ptr; 
        ptr = ptr->next; 
    }
    newNode = calloc(1, sizeof(SNode)); 
    newNode->data = data; 
    newNode->next = NULL; 
    if (prev != NULL)
    {
        prev->next = newNode;
        list->tail = newNode;  
    }
    else
    {
        list->head = newNode; 
        list->tail = newNode; 
    }
    list->len ++; 
} 

void sll_delete(SList * list, int index)
{
    int i = 0; 
    SNode * ptr = list->head, * prev = NULL, * next = NULL; 
    if (index < list->len && index > -1)
    {
        if (ptr != NULL)
        {
            next = ptr->next; 
        }
        while (++i <= index && next != NULL)
        {
            prev = ptr; 
            ptr = ptr->next; 
            next = next->next; 
        }
        // if prev and next == NULL then the only node in the table is being deleted 
        if (prev == NULL && next == NULL)
        {
            list->head = NULL; 
            list->tail = NULL; 
        } 
        // if just prev == NULL then the head is being deleted
        else if (prev == NULL && next != NULL)
        {
            list->head = next; 
        }
        // if just next == NULL then the tail is being deleted
        else if (prev != NULL && next == NULL)
        {
            list->tail = next; 
            prev->next = next; 
        }
        // else just change prev's adjacent node to next
        else
        {
            prev->next = next; 
        }
        free(ptr);
        list->len --;  
    }
} 

// return index of data
int sll_contains(SList * list, void * data, int (*compare)(void *, void *))
{
    int i = 0; 
    SNode * ptr = list->head; 
    while (ptr != NULL)
    {
        if (compare(ptr->data, data) == 0)
        {
            return i;  
        }
        ptr = ptr->next; 
        i ++; 
    }
    return -1; 
}

int sll_is_empty(SList * list)
{
    return list->len == 0; 
}

void * sll_get(SList * list, int index)
{
    if (index > -1 && index < list->len)
    {
        SNode * ptr = list->head ;
        int i = 0; 
        while (ptr != NULL && i < index)
        {
            ptr = ptr->next; 
            i ++; 
        }
        return ptr->data; 
    }
    return NULL; 
}

int sll_len(SList * list)
{
    return list->len; 
}

size_t sll_type(SList * list)
{
    return list->elementSize; 
}