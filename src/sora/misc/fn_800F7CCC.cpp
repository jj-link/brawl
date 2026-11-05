#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800F7D30(void*, int, int, int);

extern "C" void* fn_800F7CCC(int a, int b, int c) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x27ac, 0x2a);
    if (p != 0) {
        p = fn_800F7D30(p, a, b, c);
    }
    return p;
}