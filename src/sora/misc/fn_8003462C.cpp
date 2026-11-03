#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(int, unsigned long, long);
void fn_803D5878(void*, int, void*, unsigned short);
}

extern "C" int fn_8003462C(u8* self) {
    if (*(void**)(self + 0x8C) == 0 || *(u16*)(self + 0x90) == 0) {
        return 0;
    }
    if (*(int*)(self + 0xB4) != 3) {
        return 0;
    }
    if (*(u8*)(self + 0xA4) != 0) {
        return 0;
    }

    int heapType = *(int*)(self + 0x40);
    u16 count = *(u16*)(self + 0x48);
    *(u8*)(self + 0xA4) = 1;
    *(u8*)(self + 0xA5) = 0;
    *(u16*)(self + 0xA6) = 0;
    *(u16*)(self + 0xA8) = 0;

    if (count != 0) {
        if (*(void**)(self + 0xAC) != 0) {
            if (*(void**)(self + 0xAC) != 0) {
                u16 i = 0;
                while (i < *(u16*)(self + 0xB0)) {
                    void* ptr = *(void**)((char*)*(void**)(self + 0xAC) + i * 0xA0 + 0x88);
                    if (ptr != 0) {
                        free__13gfHeapManagerFPv(ptr);
                    }
                    i++;
                }
                free__13gfHeapManagerFPv(*(void**)(self + 0xAC));
                *(void**)(self + 0xAC) = 0;
            }
            *(u16*)(self + 0xB0) = 0;
            *(u16*)(self + 0xB2) = 0;
        }
        int size = count * 0xA0;
        void* buf = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(heapType, size, 0x20);
        *(void**)(self + 0xAC) = buf;
        memset(buf, 0, size);
        *(u16*)(self + 0xB0) = count;
        *(u16*)(self + 0xB2) = 0;
    }

    fn_803D5878(self + 0x58, 4, *(void**)(self + 0x50), 0x40);
    return 1;
}