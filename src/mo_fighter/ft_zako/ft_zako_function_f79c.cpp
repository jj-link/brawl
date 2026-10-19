#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_126_D8A0(void*, void*, int, void*, void*);
}

extern "C" void fn_126_F79C(void* a, void* b, int heap, void* c, void* d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x8140, heap);
    if (p) {
        fn_126_D8A0(p, b, heap, c, d);
    }
}
