#include <stdio.h>
#include <stdlib.h>
#include "block.h"
#include "bool.h"

Block *allocation_list = NULL;

Block *new_block()
{
    Block *new_block = malloc(sizeof(Block));
    if (new_block == NULL)
    {
        printf("[Error:] Sem espaço para alocar o bloco");
    }
    else
    {
        return new_block;
    }
}

void *gc_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
        return NULL;

    Block *block = new_block();

    block->size = size;
    block->alive = false;
    block->ptr = ptr;
    block->next = allocation_list;
    allocation_list = block;

    return ptr;
}

Block *find_block(void *p)
{
    Block *curr = allocation_list;
    while (curr != NULL)
    {
        if (curr->ptr == p)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void mark(Block *block)
{
    if (block == NULL || block->alive)
        return;

    block->alive = true;
    void **mem = (void **)block->ptr;
    int ptrs = block->size / sizeof(void *);

    for (int i = 0; i < ptrs; i++)
    {
        void *addr = mem[i];

        Block *next = find_block(addr);

        if (next != NULL)
        {
            mark(next);
        }
    }
}

void sweep() {
    Block **indirect = &allocation_list; 

    while (*indirect != NULL) {
        Block *block = *indirect;

        if (!block->alive) {
            *indirect = block->next; 

            printf("[GC] Liberando bloco de %zu bytes em %p\n", block->size, block->ptr);
            
            free(block->ptr);  
            free(block);      
        } else {
            block->alive = false;
            indirect = &block->next;
        }
    }
}