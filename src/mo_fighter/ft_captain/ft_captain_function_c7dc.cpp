#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_100_70(void*, int, int, int, int);

extern "C" void fn_100_C7DC(void*, int a, int b, int c, int d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x10000 - 0x3a38, b);
    if (p != 0) {
        fn_100_70(p, a, b, c, d);
    }
}
