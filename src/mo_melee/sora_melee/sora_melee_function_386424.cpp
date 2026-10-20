#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_377C48(void*, int, int, int, int);

extern "C" void fn_27_386424(void* unused, int a1, int a2, int a3, int a4) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x8014, a2);
    if (p) {
        fn_27_377C48(p, a1, a2, a3, a4);
    }
}
