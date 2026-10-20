#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_104_159D0(void* p, int a, int b, int c, int d);

extern "C" void fn_104_1D924(int unused, int a, int heap, int c, int d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1FF78, heap);
    if (p) {
        fn_104_159D0(p, a, heap, c, d);
    }
}
