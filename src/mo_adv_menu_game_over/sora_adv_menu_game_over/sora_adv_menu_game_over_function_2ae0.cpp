#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_33_2B24(void* obj, void* self);

extern "C" void fn_33_2AE0(void* self) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1dc, 0x2a);
    if (p) {
        fn_33_2B24(p, self);
    }
}
