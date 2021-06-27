typedef struct DynamicArray DynamicArray; 


DynamicArray * init(size_t elementSize);
void * get(DynamicArray * array, int index); 
void remove(DynamicArray * array, int index); 
// checks to see if element is in array and returns the index if it is, otherwise returns -1
int contains(DynamicArray * array, void * data, int (* compare)(void *, void *)); 
int is_empty(DynamicArray * array); 
int length(DynamicArray * array); 
void add(DynamicArray * array, void * data, size_t elementSize);
void sort(DynamicArray * array, int (* compare)(void *, void *)); 
