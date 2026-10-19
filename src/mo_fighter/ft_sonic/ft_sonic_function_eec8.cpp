#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_123_70(void*, void*, int, void*, void*);
}

extern "C" void fn_123_EEC8(void* unused, void* a, int heap, void* c, void* d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xD5D8, heap);
    if (obj) {
        fn_123_70(obj, a, heap, c, d);
    }
}
