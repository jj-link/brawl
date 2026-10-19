#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_72_A4(void*);

extern "C" void fn_72_10F0() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x2c4, 0xf);
    if (p != 0)
        fn_72_A4(p);
}
