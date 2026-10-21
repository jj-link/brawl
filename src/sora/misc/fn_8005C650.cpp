#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_8005C6A4(void* obj, void* a, void* b);

extern "C" void fn_8005C650(void* a, void* b) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x60, 3);
    if (p != 0) {
        fn_8005C6A4(p, a, b);
    }
}
