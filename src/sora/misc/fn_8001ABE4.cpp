#include <types.h>
#pragma force_active on

extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);

extern void* lbl_8059FFC8;

struct Header {
    u16 count;
    u16 unk2;
    char* entries;
    u32 unk8;

    void init(u16 n, char* base) {
        count = n;
        unk2 = 0;
        entries = base;
        unk8 = 0;

        s32 off;
        s32 i = 0;
        off = 0;

        while (i < count) {
            char* e = entries + off;
            gfMemFill__FPvUcUl(e, 0, 0x20);
            *(u32*)(e + 0x20) = 0;
            off += 0x30;
            i++;
            *(u32*)(e + 0x24) = 0;
            *(u32*)(e + 0x28) = 0;
            *(u32*)(e + 0x2C) = 0;
        }
    }
};

extern "C" void* fn_8001ABE4(u16 count) {
    Header* h = (Header*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(
        3, count * 0x30 + 0x1C);
    char* entries = (char*)h + 0xC;

    if (h != 0) {
        h->init(count, entries);
    }

    lbl_8059FFC8 = h;
    return h;
}
