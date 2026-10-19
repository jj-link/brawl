#include <types.h>
#pragma force_active on

extern "C" {
void* fn_106_70(void* self, int a, int b, int c, int d);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heapType);

void* fn_106_A540(int kind, int a, int b, int c, int d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x10000 - 0x7A8C, b);
    if (obj != 0) {
        obj = fn_106_70(obj, a, b, c, d);
    }
    return obj;
}
}
