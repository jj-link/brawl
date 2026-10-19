#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_126_B92C(void*, int, int, int, int);
}

extern "C" void fn_126_D828(int unused, int a, int heap, int c, int d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x8140, heap);
    if (p) {
        fn_126_B92C(p, a, heap, c, d);
    }
}
