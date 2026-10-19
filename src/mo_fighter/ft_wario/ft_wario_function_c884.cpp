#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_110_70(void*, void*, int, void*, void*);
}

extern "C" void fn_110_C884(void* unused, void* a, int heap, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xD324, heap);
    if (obj) {
        fn_110_70(obj, a, heap, b, c);
    }
}
