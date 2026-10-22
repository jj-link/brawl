#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800F19B0(void*);
extern "C" void fn_800F1AB0(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, int);

extern "C" void* fn_800F1820(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h) {
    void* p = __nw__FUlQ25Heaps8HeapType(0xE0, (int)(unsigned long)f);
    if (p)
        p = fn_800F19B0(p);
    fn_800F1AB0(p, 0, a, b, c, d, e, f, g, h, 1);
    return p;
}
