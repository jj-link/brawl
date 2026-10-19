#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_94_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_94_EC5C(void*, void* createInfo, int heap,
                            void* resources, void* instanceInfo) {
    void* fighter = __nw__FUlQ25Heaps8HeapType(0x25c0c, heap);
    if (fighter)
        fighter = fn_94_70(fighter, createInfo, heap, resources, instanceInfo);
    return fighter;
}
