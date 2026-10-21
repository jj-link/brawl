#include <types.h>
#pragma force_active on

extern "C" {

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* fn_801AB6CC(void*, void*, int);
void* fn_103_10924(void*, s32, s32);
void fn_103_109A8(void*, void*, void*, int, s32);

void* fn_103_1088C(s32 arg1, int arg2, s32 arg3, s32 arg4) {
    char* obj = (char*)__nw__FUlQ25Heaps8HeapType(0x5c, arg2);
    if (obj != nullptr) {
        obj = (char*)fn_103_10924(obj, arg1, arg3);
    }
    Init__Q34nw4r3g3d7ResFileFPv(obj + 0x40);
    void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(arg2);
    void* scn = fn_801AB6CC(allocator, 0, 1);
    fn_103_109A8(obj, obj + 0x40, scn, arg2, arg4);
    return obj;
}

}
