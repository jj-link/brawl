#include <types.h>
#pragma force_active on

namespace Heaps {
enum HeapType { HEAP_TYPE_DUMMY = 0 };
}

class gfRunnable;

extern "C" {
extern char __vt__8gfThread[];
extern char lbl_804620C4[];

void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
    void*, void*, unsigned long, unsigned long, int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_801510F4(void*, s8);
}

struct gfThread {
    void* vtable;
    char pad4[0x340 - 0x4];
    void* unk340;
    void* unk344;
    s8 unk348;
    char pad349[3];
    s32 unk34C;
    s32 unk350;
    void* unk354;
    s32 unk358;
    char pad35C[4];
    s32 unk360;
    char pad364[0xC];
    s32 unk370;
    s8 unk374;
    char pad375[3];
    void* unk378;
    s8 unk37C;
};

extern "C" gfThread* fn_80157200(gfThread* self, s32 heap)
{
    self->vtable = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        self, self, 0xF, 0x2000, 0x3A);

    self->vtable = lbl_804620C4;
    self->unk340 = lbl_804620C4 + 0xC;
    self->unk344 = lbl_804620C4 + 0x18;
    self->unk370 = 0;
    self->unk374 = 1;
    self->unk348 = 0;
    self->unk34C = 0;
    self->unk360 = 0;
    self->unk354 = 0;
    self->unk358 = 0;

    void* obj = __nw__FUlQ25Heaps8HeapType(0x360, heap);
    if (obj)
        obj = fn_801510F4(obj, 1);
    self->unk378 = obj;

    void* cb = self;
    if (self)
        cb = &self->unk340;
    ((gfThread*)self->unk378)->unk354 = cb;

    self->unk350 = heap;
    self->unk37C = 0;
    return self;
}
