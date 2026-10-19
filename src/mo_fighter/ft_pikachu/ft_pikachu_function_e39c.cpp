#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_98_70(void*, int, int, int, int);

extern "C" void fn_98_E39C(void* unused, int a, int b, int c, int d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x2AE48, b);
    if (p) {
        fn_98_70(p, a, b, c, d);
    }
}
