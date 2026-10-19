#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_113_70(void*, void*, int, void*, void*);
}

extern "C" void fn_113_FF18(void* unused, void* createInfo, int heap, void* resources, void* instanceInfo) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x20130, heap);
    if (obj)
        fn_113_70(obj, createInfo, heap, resources, instanceInfo);
}
