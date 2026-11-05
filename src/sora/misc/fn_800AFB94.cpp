#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heapType);
extern "C" void* fn_800AFC74(void* self, const char* name, s32 arg2, const char* arg3, s32 arg4);

extern "C" void fn_800AFB94(const char* name, s32 arg2, const char* arg3) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1AC, 0x2A);
    if (obj != NULL) {
        fn_800AFC74(obj, name, arg2, arg3, 0x2B);
    }
}
