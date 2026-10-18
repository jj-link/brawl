#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_28_60();
extern "C" void fn_28_450(void*, void*);

extern "C" void* fn_28_0(void* arg) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x354, 0x2a);
    if (p) {
        p = fn_28_60();
    }
    fn_28_450(p, arg);
    return p;
}
