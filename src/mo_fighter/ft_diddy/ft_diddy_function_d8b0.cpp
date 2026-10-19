#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_115_70(void*, void*, int, void*, void*);
}

extern "C" void fn_115_D8B0(void* a, void* b, int heap, void* c, void* d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x26884, heap);
    if (p) {
        fn_115_70(p, b, heap, c, d);
    }
}
