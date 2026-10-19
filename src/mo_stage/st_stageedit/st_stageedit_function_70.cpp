#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_85_A4(char*);

extern "C" void* fn_85_70() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1c94, 0xf);
    if (p) {
        p = fn_85_A4((char*)p);
    }
    return p;
}
