#pragma force_active on
typedef struct Block {
    struct Block *prev;
    struct Block *next;
    int size;
} Block;
typedef struct Heap {
    int size;
    Block *free;
    Block *allocated;
} Heap;
extern Heap *lbl_805A068C;
extern Block *fn_801D6E24(Block *, Block *);
static inline Block *DLExtract(Block *head, Block *cell)
{
    if (cell->next)
        cell->next->prev = cell->prev;
    if (cell->prev == 0)
        head = cell->next;
    else
        cell->prev->next = cell->next;
    return head;
}
void fn_801D6FC8(int heap, void *ptr) {
    Heap *hd = &lbl_805A068C[heap];
    Block *cell = (Block *)((char *)ptr - 0x20);
    hd->allocated = DLExtract(hd->allocated, cell);
    hd->free = fn_801D6E24(hd->free, cell);
}