#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_112_70(void*, void*, void*, void*, void*);
}

extern "C" void* fn_112_DBF8(void* unused, void* a, void* heap, void* c, void* d) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x297B8, (int)heap);
    if (p) {
        p = fn_112_70(p, a, heap, c, d);
    }
    return p;
}
