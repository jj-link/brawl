#include <revolution/OS/OSMutex.h>
#include <revolution/MEM/mem_expHeap.h>
#pragma force_active on
typedef struct Heap {
    char pad[0x20];
    OSMutex mutex;
    u32 attribute;
} Heap;
extern void fn_80204520(MEMiExpHeapHead*, void**);
void fn_80204818(Heap* heap, void* memBlock) {
    MEMiExpHeapHead* exp;
    MEMiExpHeapMBlock* mblock;
    MEMiExpHeapMBlock* next;
    MEMiExpHeapMBlock* prev;
    void* region[2];
    if (memBlock == 0) return;
    exp = (MEMiExpHeapHead*)((u8*)heap + 0x3c);
    mblock = (MEMiExpHeapMBlock*)((u8*)memBlock - 0x10);
    if (heap->attribute & 4) OSLockMutex(&heap->mutex);
    region[0] = (u8*)mblock - mblock->align;
    region[1] = (u8*)mblock + mblock->size + 0x10;
    prev = mblock->prev;
    next = mblock->next;
    if (prev) prev->next = next;
    else exp->usedMBlocks.head = next;
    if (next) next->prev = prev;
    else exp->usedMBlocks.tail = prev;
    fn_80204520(exp, region);
    if (heap->attribute & 4) OSUnlockMutex(&heap->mutex);
}