#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_110_1CA30(void*, void*, int, void*, void*);
}

extern "C" void* fn_110_20F38(void* unused, void* createInfo, int heap,
                               void* resources, void* instanceInfo) {
    void* fighter = __nw__FUlQ25Heaps8HeapType(0xB278, heap);
    if (fighter)
        fighter = fn_110_1CA30(fighter, createInfo, heap, resources, instanceInfo);
    return fighter;
}
