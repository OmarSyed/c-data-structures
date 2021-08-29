typedef struct BstNode Node; 
typedef struct BstTree BstTree; 

BstTree * init_tree(size_t type); 
void delete_bst(BstTree * tree); 
void bst_add(BstTree * tree, void * data, int (* compare)(void *, void *));
void bst_remove(BstTree * tree, void * data, int (* compare)(void *, void *)); 
int bst_contains(BstTree * tree, void * data, int (* compare)(void *, void *)); 
int bst_is_empty(BstTree * tree);  