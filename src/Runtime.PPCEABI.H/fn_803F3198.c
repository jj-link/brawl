typedef unsigned long u32;

typedef struct HeapBlock {
    u32 header;
    u32 x4;
    struct HeapBlock* prev;
    struct HeapBlock* next;
} HeapBlock;

void fn_803F3198(HeapBlock* block, HeapBlock** list)
{
    u32 header;
    u32 nh;
    u32 size;
    HeapBlock* next;
    u32 merged;
    u32 new_header;
    HeapBlock* head;

    header = block->header;
    size = header & ~7u;
    next = (HeapBlock*)((char*)block + size);
    nh = next->header;
    if (nh & 2u) {
        return;
    }
    merged = size + (nh & ~7u);
    new_header = (merged & ~7u) | (header & 7u);
    block->header = new_header;
    if ((new_header & 2u) == 0) {
        ((u32*)((char*)block + merged))[-1] = merged;
    }
    if ((block->header & 2u) == 0) {
        *(u32*)((char*)block + merged) &= ~4u;
    } else {
        *(u32*)((char*)block + merged) |= 4u;
    }
    head = *list;
    if (head == next) {
        *list = head->next;
    }
    if (*list == next) {
        *list = 0;
    }
    next->next->prev = next->prev;
    next->prev->next = next->next;
}
