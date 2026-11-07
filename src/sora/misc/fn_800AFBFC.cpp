#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800AFDE4(void*, const char*, int, int, int, int);
extern "C" void* fn_800AFBFC(const char* a, int b, int c, int d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1ac, 0x2a);
    if (p != 0)
        p = fn_800AFDE4(p, a, b, c, d, 0x2b);
    return p;
}