#include "bool.h"

typedef struct Block {  
    void *ptr;
    size_t size;
    bool alive; 
    struct Block *next;
} Block;    


Block *new_block();
void *gc_malloc(size_t size);