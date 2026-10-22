#include <types.h>
#pragma force_active on

struct FnSelf {
    s32 a;
    void* heap;
    void* vt;
    void* p;
    void* q;
};

extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(void* heap, u32 type, u32 align);
void* memset(void* p, s32 c, u32 n);
extern u8 lbl_80461690[];
}

extern "C" FnSelf* fn_80152B5C(FnSelf* self, void* heap) {
    self->vt = lbl_80461690;
    void* p = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(heap, 0x34, 0x20);
    self->p = p;
    if (p != 0) {
        memset(p, 0, 0x34);
    }
    self->q = 0;
    self->a = 2;
    self->heap = heap;
    return self;
}
