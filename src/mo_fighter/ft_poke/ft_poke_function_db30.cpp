#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_116_70(void*, void*, int, void*, void*);
}

extern "C" void fn_116_DB30(void* unused, void* a, int heap, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x17fdc, heap);
    if (obj) {
        fn_116_70(obj, a, heap, b, c);
    }
}
