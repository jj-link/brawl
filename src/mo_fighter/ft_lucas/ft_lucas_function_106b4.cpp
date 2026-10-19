#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_114_70(void* obj, int a, int heap, int c, int d);

extern "C" void fn_114_106B4(void*, int a, int heap, int c, int d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x48CC8, heap);
    if (obj != 0) {
        fn_114_70(obj, a, heap, c, d);
    }
}
