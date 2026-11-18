#include <types.h>
typedef int bool;
typedef struct OSModuleHeader OSModuleHeader;
#include <revolution/MEM/mem_expHeap.h>
#include <revolution/MEM/mem_heapCommon.h>
#pragma force_active on

static MEMiExpHeapHead* GetExpHeapHeadPtrFromHeapHead_(const MEMiHeapHead* heap) {
    return AddU32ToPtr(heap, sizeof(MEMiHeapHead));
}
static void* GetMemPtrForMBlock_(MEMiExpHeapMBlock* mblock) {
    return AddU32ToPtr(mblock, sizeof(MEMiExpHeapMBlock));
}
static void* GetMBlockEndAddr_(MEMiExpHeapMBlock* mblock) {
    return AddU32ToPtr(GetMemPtrForMBlock_(mblock), mblock->size);
}

u32 fn_802048E4(MEMiHeapHead* heap, s32 align) {
    MEMiExpHeapMBlock* it;
    MEMiExpHeapHead* exp;
    u32 smallestPadding;
    u32 biggestSize;

    align = __abs(align);
    exp = GetExpHeapHeadPtrFromHeapHead_(heap);
    LockHeap(heap);
    biggestSize = 0;
    smallestPadding = 0xFFFFFFFF;
    for (it = exp->freeMBlocks.head; it != NULL; it = it->next) {
        void* start = GetMemPtrForMBlock_(it);
        void* alignStart = ROUND_UP_PTR(GetUIntPtr(start), align);
        void* end = GetMBlockEndAddr_(it);
        if (alignStart < end) {
            u32 size = GetOffsetFromPtr(alignStart, end);
            u32 padding = GetOffsetFromPtr(start, alignStart);
            if (biggestSize < size ||
                (biggestSize == size && smallestPadding > padding)) {
                biggestSize = size;
                smallestPadding = padding;
            }
        }
    }
    UnlockHeap(heap);
    return biggestSize;
}
