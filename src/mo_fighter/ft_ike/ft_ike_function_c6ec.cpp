#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_119_70(void*, void*, int, void*, void*);
}

extern "C" void fn_119_C6EC(void* self, void* a, int heap, void* c, void* d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0xAB7C, heap);
    if (p)
        fn_119_70(p, a, heap, c, d);
}
