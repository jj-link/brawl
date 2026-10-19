#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80_A4(void*);

extern "C" void* fn_80_70() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1014, 0xF);
    if (p) {
        p = fn_80_A4(p);
    }
    return p;
}
