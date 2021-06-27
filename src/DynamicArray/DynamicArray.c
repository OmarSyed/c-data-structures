#include "DynamicArray.h"
#include <strings.h>

struct DynamicArray
{
	void * data;
	size_t elementSize;  
	int len; 
}

DynamicArray * init(size_t elementSize)
{
	DynamicArray * newArray = calloc(1, sizeof(DynamicArray)); 
	newArray->data = NULL; 
	newArray->len = 0; 
	newArray->elementSize = elementSize;
	return newArray;  
}

// o(1) complexity 
void * get(DynamicArray * array, int index)
{
	void * data = index >= array->len ? NULL : array->data + (array->elementSize * index);
	return data; 
}

// left shifts all elements in array
void shiftArray(void * array, size_t elementSize, int start, int end)
{
	int i; 
	for (i = start; i < end; i ++)
	{
		*(array->data + (elementSize * i)) = *(array->data + (elementSize * (i + 1))); 
	}
}

// removal is o(n)
void remove(DynamicArray * array, int index)
{
	if (index < array->len)
	{
		shiftArray(array->data, array->elementSize, index, array->len); 
	}
}


int contains(DynamicArray * array, void * data, int (* compare)(void *, void *))
{
	int i, j, notEqual; 
	for (i = 0; i < array->len; i += array->elementSize)
	{
		if (compare(data, array->data + i) == 0)
		{
			return i; 
		}
	}
	return -1; 
}

int is_empty(DynamicArray * array)
{
	return array->len < 1; 
}