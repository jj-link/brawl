#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_46_A4(void*);

extern "C" void fn_46_70() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x764, 0x0F);
    if (p != 0) {
        fn_46_A4(p);
    }
}
