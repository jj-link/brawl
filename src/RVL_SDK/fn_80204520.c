#include <revolution/MEM/mem_expHeap.h>
#pragma force_active on

typedef struct Region {
    void* start;
    void* end;
} Region;

static inline MEMiExpHeapMBlock* RemoveBlock(MEMiExpHeapMBlockList* list, MEMiExpHeapMBlock* block)
{
    MEMiExpHeapMBlock* prev = block->prev;
    MEMiExpHeapMBlock* next = block->next;
    if (prev) prev->next = next;
    else list->head = next;
    if (next) next->prev = prev;
    else list->tail = prev;
    return prev;
}

static inline void InsertBlock(MEMiExpHeapMBlockList* list, MEMiExpHeapMBlock* prev, MEMiExpHeapMBlock* block)
{
    MEMiExpHeapMBlock* next;
    block->prev = prev;
    if (prev) {
        next = prev->next;
        prev->next = block;
    } else {
        next = list->head;
        list->head = block;
    }
    block->next = next;
    if (next) next->prev = block;
    else list->tail = block;
}

static inline MEMiExpHeapMBlock* InitBlock(Region* region, u16 state)
{
    MEMiExpHeapMBlock* block = region->start;
    block->state = state;
    block->settings = 0;
    block->size = (u32)region->end - ((u32)block + 0x10);
    block->prev = NULL;
    block->next = NULL;
    return block;
}

s32 fn_80204520(MEMiExpHeapMBlockList* list, Region* region)
{
    Region merged = *region;
    MEMiExpHeapMBlock* prev = NULL;
    MEMiExpHeapMBlock* cur = list->head;
    MEMiExpHeapMBlock* block;

    while (cur) {
        if ((u32)cur < (u32)region->start) {
            prev = cur;
        } else {
            if ((u32)cur == (u32)region->end) {
                merged.end = (u8*)cur + cur->size + 0x10;
                RemoveBlock(list, cur);
            }
            break;
        }
        cur = cur->next;
    }
    if (prev && (u8*)prev + prev->size + 0x10 == region->start) {
        merged.start = prev;
        prev = RemoveBlock(list, prev);
    }
    if ((u32)merged.end - (u32)merged.start < 0x10) return 0;
    block = InitBlock(&merged, 0x4652);
    InsertBlock(list, prev, block);
    return 1;
}
