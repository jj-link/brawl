#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_6_A454(void*);
extern "C" void fn_6_A6BC(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);

extern "C" void* fn_6_A3B4(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x268, 0x2a);
    if (p)
        p = fn_6_A454(p);
    fn_6_A6BC(p, a, b, c, d, e, f, g, h, i);
    return p;
}
