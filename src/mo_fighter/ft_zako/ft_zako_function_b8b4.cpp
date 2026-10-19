#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_126_99B8(void*, void*, int, void*, void*);
}

extern "C" void* fn_126_B8B4(void* p0, void* p1, int heap, void* p3, void* p4) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x8140, heap);
    if (obj)
        obj = fn_126_99B8(obj, p1, heap, p3, p4);
    return obj;
}
