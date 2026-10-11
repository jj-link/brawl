typedef unsigned long u32;

typedef struct HeapBlock {
    u32 header;
    u32 reserved;
    struct HeapBlock* prev;
    struct HeapBlock* next;
} HeapBlock;

typedef struct Segment {
    struct Segment* next;
    struct Segment* prev;
    u32 largest_free;
    u32 size_header;
} Segment;

extern void fn_803F3198(HeapBlock* block, HeapBlock** list);

static inline HeapBlock* JoinPrevious(HeapBlock* original, HeapBlock** list, u32 previous_size) {
    HeapBlock* block = original;
    HeapBlock* head;
    HeapBlock* next;

    if (previous_size & 2u) {
        return block;
    }
    block = (HeapBlock*)((char*)original - previous_size);
    block->header &= 7u;
    block->header = (block->header & 7u) | ((previous_size + (original->header & ~7u)) & ~7u);
    if ((block->header & 2u) == 0) {
        u32 total = previous_size + (original->header & ~7u);
        ((u32*)((char*)block + total))[-1] = total;
    }
    head = *list;
    if (head == original) {
        *list = head->next;
    }
    original->next->prev = original->prev;
    next = original->next;
    next->prev->next = next;
    return block;
}

static inline void MergePrevious(HeapBlock** block_ptr, HeapBlock** list) {
    if (((*block_ptr)->header & 4u) == 0) {
        *block_ptr = JoinPrevious(*block_ptr, list, ((u32*)*block_ptr)[-1]);
    }
}

/* The segment's final word owns its circular free list. Boundary tags
   permit coalescing with the preceding block before merging the successor. */
void fn_803F3048(Segment* segment, HeapBlock* block) {
    u32 header;
    HeapBlock* end;
    u32 size;
    HeapBlock** list;
    HeapBlock* head;
    HeapBlock* merged;

    header = block->header;
    block->header = header & ~2u;
    size = header & ~7u;
    end = (HeapBlock*)((char*)block + size);
    end->header &= ~4u;
    ((u32*)end)[-1] = size;
    list = (HeapBlock**)((char*)segment + (segment->size_header & ~7u) - 4);
    head = *list;
    if (head != 0) {
        HeapBlock* previous = head->prev;
        block->prev = previous;
        previous->next = block;
        block->next = *list;
        (*list)->prev = block;
        *list = block;
        merged = block;
        MergePrevious(&merged, list);
        *list = merged;
        fn_803F3198(merged, list);
    } else {
        *list = block;
        block->prev = block;
        block->next = block;
    }
    size = (*list)->header & ~7u;
    if (segment->largest_free < size) {
        segment->largest_free = size;
    }
}
