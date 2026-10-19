#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_89_A4(void*);

extern "C" void fn_89_70() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x3C4, 0xF);
    if (p != 0)
        fn_89_A4(p);
}
