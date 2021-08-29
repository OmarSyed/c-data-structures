typedef struct DynamicArray DynamicArray; 


DynamicArray * init_darray(size_t elementSize);
void free_darray(DynamicArray * arr);
void * darray_get(DynamicArray * array, int index); 
void darray_remove(DynamicArray * array, int index); 
int darray_contains(DynamicArray * array, void * data, int (* compare)(void *, void *)); 
int darray_is_empty(DynamicArray * array); 
int darray_length(DynamicArray * array); 
void darray_add(DynamicArray * array, void * data);
void darray_quick_sort(DynamicArray * array, int low, int high, int (* compare)(void *, void *)); 
void darray_selection_sort(DynamicArray * array, int (* compare)(void *, void *));
