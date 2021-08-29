#include <stdlib.h>
#include "StringBuilder.h"
#include "../DynamicArray/DynamicArray.h"

DynamicArray * listOfStringsToFree = NULL;  

struct StringBuilder
{
    DynamicArray * str; 
}; 

StringBuilder * init_string()
{
    StringBuilder * newStr = calloc(1, sizeof(StringBuilder)); 
    newStr->str = init_darray(sizeof(char)); 
    return newStr; 
} 

void free_string(StringBuilder * str)
{
    free_darray(str->str); 
    free(str); 
}

void str_append(StringBuilder * str, char * s)
{
    int i , len = strlen(s);
    for (i = 0; i < len; i ++)
    {
        darray_add(str->str, s+i);
    }  
    char_append(str, '\0');
}

void char_append(StringBuilder * str, char s)
{
    char * c = calloc(1, sizeof(char)); 
    *c = s; 
    darray_add(str->str, &c); 
}

char * copy_substr(StringBuilder * str1, int start, int end)
{
    if (listOfStringsToFree == NULL)
    {
        listOfStringsToFree = init_darray(sizeof(char *)); 
    } 
    int i;
    char * substring = calloc((end-start)+1, sizeof(char));  
    for (i = 0; i < end-start; i ++)
    {
        substring[i] = darray_get(str1->str, i); 
    }
    substring[i] = '\0'; 
    darray_add(listOfStringsToFree, substring); 
    return substring;
}

char * substring(StringBuilder * str, int low, int high)
{
    return copy_substr(str, low, high); 
}

char charAt(StringBuilder * str, int i)
{
    return darray_get(str->str, i); 
} 

// deletes the first instance of the substring
StringBuilder * deleteSubstring(StringBuilder * str, int low, int high)
{
    StringBuilder * newStr = init_string(); 
    int i; 
    for (i = 0; i < low; i ++)
    {
        char_append(str, charAt(str, i)); 
    }
    for (i = high; i < str_len(str); i ++)
    {
        char_append(str, charAt(str, i)); 
    }
    char_append(str, '\0');
    free_string(str); 
    return newStr; 
} 


int delimiter_equals_substring(StringBuilder * str, int start, int end, char * delimiter)
{
    int i = start, j = end, k = 0, l = strlen(delimiter)-1; 
    if (end - start + 1 != l+1)
    {
        return 0; 
    }
    while (i <= j && k <= l)
    {
        if (charAt(str, i) != delimiter[0] || charAt(str, j) != delimiter[l])
        {
            return 0;  
        }
        i ++; 
        j --; 
        k ++; 
        l --; 
    }
    return 1; 
}

// returns the length of the string array
int str_split(StringBuilder * str, char * delimiter, char ** result)
{
    int delim_len = strlen(delimiter), num_strings = 0; 
    result = NULL; 
    if (delim_len <= str_len(str))
    { 
        int i, len = 0;
        char * curr_str = calloc(1, sizeof(char)); 
        for (i = 0; i < str_len(str) - delim_len; i ++)
        {
            if (delimiter_equals_substring(str, i, i + delim_len - 1, delimiter))
            {
                if (result == NULL)
                {
                    result = calloc(++num_strings, sizeof(char *)); 
                }
                else
                {
                    result = realloc(result, sizeof(char *) * ++num_strings); 
                }
                curr_str[len] = '\0'; 
                result[num_strings] = curr_str; 
                curr_str = calloc(1, sizeof(char)); 
                len = 0;
                i += delim_len - 1; 
                continue; 
            }
            curr_str = realloc(curr_str, sizeof(char) * ++len+1);
            curr_str[len-1] = charAt(str, i); 
        }
        free(curr_str); 
        return num_strings; 
    }
}

int str_len(StringBuilder * str)
{
    return darray_length(str->str);
}