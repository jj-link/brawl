#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_126_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_126_9820(void* a, void* b, int c, void* d, void* e) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x8140, c);
    if (p)
        p = fn_126_70(p, b, c, d, e);
    return p;
}
