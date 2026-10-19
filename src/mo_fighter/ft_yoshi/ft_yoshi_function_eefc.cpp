#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_95_70(void*, int, int, int, int);
}

extern "C" void fn_95_EEFC(void* unused, int a, int heap, int c, int d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x222b0, heap);
    if (p) {
        fn_95_70(p, a, heap, c, d);
    }
}
