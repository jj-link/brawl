extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_99_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_99_BA08(void*, void* createInfo, int heap,
                           void* resources, void* instanceInfo) {
    void* fighter = __nw__FUlQ25Heaps8HeapType(0xe208, heap);
    if (fighter)
        fighter = fn_99_70(fighter, createInfo, heap, resources, instanceInfo);
    return fighter;
}
