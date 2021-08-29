typedef struct SinglyLinkedList SList; 

SList * init_sll(size_t type); 
void free_sll(SList * list);
void sll_add(SList * list, void * data); 
void sll_delete(SList * list, int index); 
int sll_contains(SList * list, void * data, int (*compare)(void *, void *)); 
int sll_is_empty(SList * list); 
void * sll_get(SList * list, int index); 
int sll_len(SList * list);
size_t sll_type(SList * list);
