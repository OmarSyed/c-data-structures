typedef struct StringBuilder StringBuilder; 

StringBuilder * init_string(); 
void free_string(StringBuilder * str); 
void str_append(StringBuilder * str, char * s); 
int str_len(StringBuilder * str); 
char * substring(StringBuilder * str, int low, int high); 
char charAt(StringBuilder * str, int i); 
StringBuilder * deleteSubstring(StringBuilder * str, int low, int high); 
int str_split(StringBuilder * str, char * delimiter, char ** result); 