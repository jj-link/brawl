#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_83_A4();

extern "C" void fn_83_2DF0() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x704, 0xF);
    if (p != 0) {
        fn_83_A4();
    }
}
