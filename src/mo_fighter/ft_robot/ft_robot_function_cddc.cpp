#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_120_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_120_CDDC(void*, void* createInfo, int heap,
                              void* resources, void* instanceInfo) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x122a4, heap);
    if (obj)
        obj = fn_120_70(obj, createInfo, heap, resources, instanceInfo);
    return obj;
}
