typedef struct DoublyLinkedList DList; 

DList * init_dll(size_t type); 
void free_dll(DList * list);
void dll_add(DList * list, void * data); 
void dll_delete(DList * list, int index); 
int dll_contains(DList * list, void * data, int (*compare)(void *, void *)); 
int dll_is_empty(DList * list); 