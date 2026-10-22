#pragma force_active on
typedef unsigned int u32;

typedef struct Block {
    struct Block* prev;
    struct Block* next;
    int sz;
} Block;

Block* fn_801D6E24(Block* list, Block* block) {
    Block* prev = 0;
    Block* cur = list;

    while (cur != 0) {
        if ((u32)block <= (u32)cur) break;
        prev = cur;
        cur = cur->next;
    }

    block->next = cur;
    block->prev = prev;

    if (cur != 0) {
        cur->prev = block;
        if ((void*)((u32)block + block->sz) == (void*)cur) {
            block->sz = block->sz + cur->sz;
            cur = cur->next;
            block->next = cur;
            if (cur != 0) {
                cur->prev = block;
            }
        }
    }

    if (prev != 0) {
        prev->next = block;
        if ((void*)((u32)prev + prev->sz) == (void*)block) {
            prev->sz = prev->sz + block->sz;
            prev->next = cur;
            if (cur != 0) {
                cur->prev = prev;
            }
        }
        return list;
    }
    return block;
}
