#include <types.h>
#pragma force_active on

extern "C" void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
extern "C" void* fn_801AB6CC(void*, void*, int);

struct S8000E7B0 {
    u32 m0;
    void* m4;
    u32 m8;
    u32 a : 8;
    u8 b : 1;
    u8 c : 3;
    u8 d : 4;
    u16 e;
    u32 m10;
    u32 m14;
};

extern "C" S8000E7B0* fn_8000E7B0(S8000E7B0* p) {
    u8 buf[8];
    p->m0 = 0;
    p->a = 0;
    p->m4 = 0;
    p->b = 1;
    p->m8 = 0;
    p->c = 0;
    p->e = 0;
    p->m10 = 0;
    p->m14 = 0;
    p->m4 = fn_801AB6CC(getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(2), buf, 0x140);
    return p;
}
