#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_102_70(void*, void*, int, void*, void*);
}

extern "C" void fn_102_C01C(void* unused, void* a, int heap, void* c, void* d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x14180, heap);
    if (p) {
        fn_102_70(p, a, heap, c, d);
    }
}
