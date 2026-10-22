#include <types.h>
#pragma force_active on

extern "C" char lbl_804616A4[];
extern "C" void* memset(void*, int, unsigned long);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(int, unsigned long, long);

struct Fn80152970 {
    s32 f0;
    void* f4;
    void* f8;
    void* fC;
    void* f10;
};

extern "C" Fn80152970* fn_80152970(Fn80152970* self, void* heap) {
    self->f8 = lbl_804616A4;
    void* p = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll((int)heap, 0x34, 0x20);
    self->fC = p;
    if (p != 0) {
        memset(p, 0, 0x34);
    }
    self->f10 = 0;
    self->f0 = 1;
    self->f4 = heap;
    return self;
}
