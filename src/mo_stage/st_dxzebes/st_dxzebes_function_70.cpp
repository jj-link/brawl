#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_84_A4();

extern "C" void fn_84_70() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x9fc, 0xf);
    if (p != 0) {
        fn_84_A4();
    }
}
