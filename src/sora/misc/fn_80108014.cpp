#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_80108068(void*, void*, unsigned int);

extern "C" void fn_80108014(void* a, unsigned int b) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x3C, 0x28);
    if (p) {
        fn_80108068(p, a, b);
    }
}
