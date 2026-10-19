#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_108_70(void*, void*, int, void*, void*);
}

extern "C" void fn_108_E624(void* unused, void* a, int heap, void* c, void* d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1D0E4, heap);
    if (p) {
        fn_108_70(p, a, heap, c, d);
    }
}
