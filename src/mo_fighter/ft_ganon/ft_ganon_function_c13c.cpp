#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_109_70(void*, void*, int, void*, void*);
}

extern "C" void fn_109_C13C(void*, void* a1, int heap, void* a3, void* a4) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xC9A8, heap);
    if (obj) {
        fn_109_70(obj, a1, heap, a3, a4);
    }
}
