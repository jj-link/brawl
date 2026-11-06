#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800B2BEC(void*, int, int, int, int, int, int);
extern "C" void* fn_800B2318(int a, int b, int c, int heap) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x60, heap);
    if (p != 0)
        p = fn_800B2BEC(p, 0, b, c, a, 0, heap);
    return p;
}