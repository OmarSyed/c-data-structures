#include <stdlib.h>
#include "DoublyLinkedList.h"

typedef struct DNode
{
    DNode * prev; 
    DNode * next; 
    void * data; 
} DNode;

struct DoublyLinkedList
{
    DNode * head; 
    DNode * tail; 
    size_t elementSize; 
    int len; 
};

DList * init_dll(size_t type)
{
    DList * newList = calloc(1, sizeof(DList)); 
    newList->head = NULL;
    newList->tail = NULL; 
    newList->elementSize = type; 
    newList->len = 0; 
    return newList; 
} 

void free_dll(DList * list)
{
    while (list->len > 0)
    {
        dll_delete(list, 0); 
    }
    free(list); 
}

void dll_add(DList * list, void * data)
{
    DNode * newData = calloc(1, sizeof(DNode)); 
    newData->data = data; 
    newData->next = NULL; 
    newData->prev = list->tail;
    if (list->len < 1)
    {
        list->head = newData; 
    } 
    else
    {
        list->tail->next = newData; 
    }
    list->tail = newData; 
    list->len ++; 
}

void dll_delete(DList * list, int index)
{
    if (index > -1 && index < list->len)
    {
        DNode * ptr = list->head;
        int i = 0;  
        while (ptr != NULL && i < index)
        {
            ptr = ptr->next; 
        }
        if (ptr->prev != NULL)
        {
            ptr->prev->next = ptr->next; 
        }
        if (ptr->next != NULL)
        {
            ptr->next->prev = ptr->prev; 
        }
        if (ptr == list->head)
        {
            list->head = ptr->next;
        }
        if (ptr == list->tail)
        {
            list->tail = ptr->prev; 
        }
        free(ptr); 
        list->len --; 
    }
} 

int dll_contains(DList * list, void * data, int (*compare)(void *, void *))
{
    DNode * ptr = list->head;
    int i = 0;  
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

int dll_is_empty(DList * list)
{
    return list->len < 1; 
}