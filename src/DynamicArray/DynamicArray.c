#include "DynamicArray.h"
#include <stddef.h>
#include <stdlib.h>

struct DynamicArray
{
	void * data;
	size_t element_size;  
	int len; 
	int lastUsedIndex; 
};


DynamicArray * init_darray(size_t element_size)
{
	DynamicArray * newArray = calloc(1, sizeof(DynamicArray)); 
	newArray->data = NULL; 
	newArray->len = 0; 
	newArray->element_size = element_size;
	newArray->lastUsedIndex = -1; 
	return newArray;  
}

void free_darray(DynamicArray * arr)
{
	int i; 
	for (i = arr->len * arr->element_size; i >= 0; i --)
	{
		// free all bytes in array
		free((char *)arr->data+i); 
	}
	free(arr); 
}

// o(1) complexity 
void * darray_get(DynamicArray * array, int index)
{
	void * data = index >= array->len ? NULL : (char *) array->data + (array->element_size * index);
	return data; 
}

// left shifts all elements in array
void shiftArray(char * array, size_t element_size, int start, int end)
{
	int i; 
	for (i = start; i < end; i ++)
	{
		*(array + (element_size * i)) = *(array + (element_size * (i + 1))); 
	}
}

// removal is o(n)
void darray_remove(DynamicArray * array, int index)
{
	if (index < array->lastUsedIndex + 1)
	{
		shiftArray(array->data, array->element_size, index, array->lastUsedIndex+1); 
		--array->lastUsedIndex; 
	}
}

int darray_contains(DynamicArray * array, void * data, int (* compare)(void *, void *))
{
	int i, j, notEqual; 
	for (i = 0; i < array->lastUsedIndex + 1; i += array->element_size)
	{
		if (compare(data, (char *) array->data + i) == 0)
		{
			return i; 
		}
	}
	return -1; 
}

int darray_is_empty(DynamicArray * array)
{
	return array->lastUsedIndex < 0; 
}

int darray_length(DynamicArray * array)
{
	return array->lastUsedIndex + 1; 
}

void darray_add(DynamicArray * array, void * data)
{
	if (array->lastUsedIndex < array->len)
	{
		// cast array to char * so that you can perform pointer arithmetic
		*((char *)array->data + (array->element_size * ++array->lastUsedIndex)) = data; 
	}
	else
	{
		// allocate more memory 
		void * newArray = realloc(array->data, array->element_size * array->len * 2 + 1); 
		array->data = newArray; 
		array->len *= 2 + 1; 
		// call add function again to add to array
		add(array, data);
	}
}

// swap elements at indices i and j
void swap(DynamicArray * array, int i, int j)
{
	void * i_ptr, * j_ptr, * temp = calloc(1, array->element_size); 
	i_ptr = (char *) array->data + (i * array->element_size);
	j_ptr = (char *) array->data + (j * array->element_size);
	memcpy(temp, j_ptr, array->element_size); 
	memcpy(j_ptr, i_ptr, array->element_size); 
	memcpy(i_ptr, temp, array->element_size);
	free(temp);
}

void darray_selection_sort(DynamicArray * array, int (* compare)(void *, void *))
{
	int i, j;  
	void * i_ptr, * j_ptr; 
	for (i = 0; i < array->lastUsedIndex + 1; i ++)
	{
		for (j = i + 1; j < array->lastUsedIndex + 1; j ++)
		{
			i_ptr = (char *) array->data + (i * array->element_size);
			j_ptr = (char *) array->data + (j * array->element_size);
			if (compare(j_ptr, i_ptr) < 0)
			{
				swap(array, i, j);
			}
		}
	}
}

int partition(DynamicArray * array, int low, int high, int pivot, int (* compare)(void *, void *))
{
	int newPivot = low, i;
	void * pivot_ptr, * i_ptr;  
	for (i = low; i < high; i ++)
	{
		i_ptr = (char *)array->data + (array->element_size * i); 
		pivot_ptr = (char *)array->data + (array->element_size * pivot); 
		if (compare(i_ptr, pivot_ptr) < 0)
		{
			swap(array, i, newPivot); 
			newPivot ++; 
		}
	}
	swap(array, pivot, newPivot); 
	return newPivot; 
}

void darray_quick_sort(DynamicArray * array, int low, int high, int (* compare)(void *, void *))
{
	int pivot = partition(array, 0, array->lastUsedIndex+1, array->lastUsedIndex, compare);
	if (low < high)
	{
		quick_sort(array, low, pivot-1, compare); 
		quick_sort(array, pivot+1, high, compare); 
	}
}