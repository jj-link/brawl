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
extern "C" void *fn_8005B2FC(Heap *heap, unsigned int size) {
    unsigned int want = (size + 0x1f) & ~0x1f;
    Block *cur = heap->free;
    while (cur != 0) {
        if (cur->size >= want) {
            if (cur->size < want + 0x40) {
                if (cur->prev)
                    cur->prev->next = cur->next;
                else
                    heap->free = cur->next;
                if (cur->next)
                    cur->next->prev = cur->prev;
                if (heap->allocated)
                    heap->allocated->prev = cur;
                cur->next = heap->allocated;
                cur->prev = 0;
                cur->used = 1;
                heap->allocated = cur;
            } else {
                Block *nb = (Block *)((char *)cur + want);
                nb = (Block *)((char *)nb + 0x20);
                nb->prev = cur->prev;
                nb->next = cur->next;
                nb->size = cur->size - want - 0x20;
                nb->used = 0;
                nb->after = cur->after;
                if (cur->after)
                    cur->after->before = nb;
                nb->before = cur;
                cur->after = nb;
                if (cur->prev)
                    cur->prev->next = nb;
                else
                    heap->free = nb;
                if (cur->next)
                    nb->next->prev = nb;
                if (heap->allocated)
                    heap->allocated->prev = cur;
                cur->next = heap->allocated;
                cur->prev = 0;
                cur->size = want;
                cur->used = 1;
                heap->allocated = cur;
            }
            return (char *)cur + 0x20;
        }
        cur = cur->next;
    }
    return 0;
}
