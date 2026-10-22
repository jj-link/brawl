#include <types.h>
#pragma force_active on

namespace Heaps {
enum HeapType { HEAP_TYPE_DUMMY = 0 };
}

class gfRunnable;

extern int __vt__8gfThread[];
extern int lbl_80461368[];

class gfThread {
public:
    void* vtable;
    char pad4[0x340 - 0x4];
    s32 unk340;
    s32 unk344;
    s32 unk348;
    s8 unk34C;
    s8 unk34D;
    s8 unk34E;
    char pad34F[1];
    s32 unk350;
    char pad354[4];
    s8 unk358;

    void createThread(gfRunnable* runnable, u32 stackSize, u32 arg2, Heaps::HeapType heap);
};

extern "C" gfThread* fn_801510F4(gfThread* arg0, s8 arg1) {
    arg0->vtable = __vt__8gfThread;
    arg0->createThread((gfRunnable*)arg0, 0x1F, 0x1000, (Heaps::HeapType)0x3A);
    arg0->vtable = lbl_80461368;
    arg0->unk340 = 0;
    arg0->unk344 = 0;
    arg0->unk348 = 0;
    arg0->unk34C = 0;
    arg0->unk34D = 0;
    arg0->unk34E = 1;
    arg0->unk350 = 0;
    arg0->unk358 = arg1;
    return arg0;
}
