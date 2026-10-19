#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_105_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_105_12E00(int, void* createInfo, int heap, void* resources, void* instanceInfo) {
    void* fighter = __nw__FUlQ25Heaps8HeapType(0x1FE50, heap);
    if (fighter)
        fighter = fn_105_70(fighter, createInfo, heap, resources, instanceInfo);
    return fighter;
}
