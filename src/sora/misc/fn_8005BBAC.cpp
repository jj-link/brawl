#pragma force_active on
struct Block {
    Block *prev, *next, *before, *after;
    unsigned int size;
    unsigned char used;
};
struct Heap {
    char pad[0x3c];
    Block *allocated;
    Block *free;
};
extern "C" void fn_8005BBAC(Heap *heap, void *ptr) {
    Block *block = (Block *)((char *)ptr - 0x20);
    if (block->prev)
        block->prev->next = block->next;
    else
        heap->allocated = block->next;
    if (block->next)
        block->next->prev = block->prev;

    Block *left = 0;
    if (block->before && !block->before->used)
        left = block->before;
    Block *right = 0;
    if (block->after && !block->after->used)
        right = block->after;
    if (left) {
        if (right) {
            if (right->prev)
                right->prev->next = right->next;
            else
                heap->free = right->next;
            if (right->next)
                right->next->prev = right->prev;
            left->size += block->size + right->size + 0x40;
            left->after = right->after;
            if (right->after)
                right->after->before = left;
        } else {
            left->size += block->size + 0x20;
            left->after = block->after;
            if (block->after)
                block->after->before = left;
        }
    } else if (right) {
        if (right->prev)
            right->prev->next = block;
        else
            heap->free = block;
        if (right->next)
            right->next->prev = block;
        block->prev = right->prev;
        block->next = right->next;
        block->size += right->size + 0x20;
        block->used = 0;
        block->after = right->after;
        if (right->after)
            right->after->before = left;
    } else {
        if (heap->free)
            heap->free->prev = block;
        block->next = heap->free;
        block->prev = 0;
        block->used = 0;
        heap->free = block;
    }
}