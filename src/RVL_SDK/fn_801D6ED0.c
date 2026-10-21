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

static inline Block *DLInsert(Block *head, Block *cell)
{
    cell->next = head;
    cell->prev = 0;
    if (head)
        head->prev = cell;
    return cell;
}

void *fn_801D6ED0(int heap, int size)
{
    Heap *hd;
    Block *cell;
    Block *newcell;
    unsigned int remaining;

    hd = &lbl_805A068C[heap];
    size = (size + 0x3f) & ~0x1f;

    for (cell = hd->free; cell; cell = cell->next) {
        if (size <= cell->size)
            break;
    }

    if (cell == 0)
        return 0;

    remaining = cell->size - size;
    if (remaining < 0x40) {
        hd->free = DLExtract(hd->free, cell);
    } else {
        cell->size = size;
        newcell = (Block *)((char *)cell + size);
        newcell->size = remaining;
        newcell->prev = cell->prev;
        newcell->next = cell->next;

        if (newcell->next)
            newcell->next->prev = newcell;
        if (newcell->prev)
            newcell->prev->next = newcell;
        else
            hd->free = newcell;
    }

    hd->allocated = DLInsert(hd->allocated, cell);
    return (char *)cell + 0x20;
}
