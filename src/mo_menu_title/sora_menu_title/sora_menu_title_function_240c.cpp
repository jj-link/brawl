#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" u32 fn_8018F1D0(void*);
extern "C" u8* fn_8018F128(void*, u32);
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);

struct Obj {
    u8 pad[0x50];
    u8* res;
    u8 pad2[0x14];
    u8** arr;
    u32 count;
};

struct Entry {
    u8 pad[8];
    s32 off;
    u8 pad2[0x12];
    u16 n;

    u8* getData() {
        s32 mask = -off;
        u32 addr = (u32)((u8*)this + off);
        mask = (mask | off) >> 31;
        return (u8*)(addr & mask);
    }
};

extern "C" void fn_24_240C(Obj* o) {
    o->count = fn_8018F1D0(o->res + 8);
    o->arr = (u8**)__nwa__FUlQ25Heaps8HeapType(o->count * 4, 0x2a);

    u32 i = 0;
    while (i < o->count) {
        Entry& e = *(Entry*)fn_8018F128(o->res + 8, i);
        const u16 n = e.n;

        o->arr[i] = (u8*)__nwa__FUlQ25Heaps8HeapType(n * 4, 0x2a);
        memset(o->arr[i], 0, (u32)n * 4);

        u8* src = e.getData();
        for (int j = 0; j < n * 4; j++) {
            o->arr[i][j] = src[j];
        }
        i++;
    }
}
