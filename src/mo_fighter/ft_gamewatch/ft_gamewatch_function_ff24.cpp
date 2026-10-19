#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_107_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_107_FF24(void*, void* a, int heap, void* c, void* d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1FDE4, heap);
    if (obj)
        return fn_107_70(obj, a, heap, c, d);
    return obj;
}
