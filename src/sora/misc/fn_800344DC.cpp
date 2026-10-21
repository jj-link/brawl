#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(int, unsigned long, long);
}

extern "C" int fn_800344DC(u8* self, int count) {
    if (count == 0) {
        return 0;
    }

    if (self + 0x8C != 0) {
        if (*(void**)(self + 0x8C) != 0) {
            free__13gfHeapManagerFPv(*(void**)(self + 0x8C));
            *(void**)(self + 0x8C) = 0;
        }
        *(u16*)(self + 0x90) = 0;
    }

    int size = count * 0x60;
    *(void**)(self + 0x8C) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(
        *(int*)(self + 0x40), size, 0x20);
    memset(*(void**)(self + 0x8C), 0, size);
    *(u16*)(self + 0x90) = count;

    if (self + 0x84 != 0) {
        if (*(void**)(self + 0x84) != 0) {
            free__13gfHeapManagerFPv(*(void**)(self + 0x84));
            *(void**)(self + 0x84) = 0;
        }
        *(u16*)(self + 0x88) = 0;
        *(u16*)(self + 0x8A) = 0;
    }

    size = count * 0x2020;
    *(void**)(self + 0x84) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(
        *(int*)(self + 0x40), size, 0x20);
    memset(*(void**)(self + 0x84), 0, size);
    *(u16*)(self + 0x8A) = count;
    *(u16*)(self + 0x88) = 0;
    return 1;
}
