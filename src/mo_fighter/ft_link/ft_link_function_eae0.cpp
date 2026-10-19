#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_93_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_93_EAE0(void* self, void* createInfo, int heap,
                            void* resources, void* instanceInfo) {
    void* fighter = __nw__FUlQ25Heaps8HeapType(0x1a360, heap);
    if (fighter)
        fighter = fn_93_70(fighter, createInfo, heap, resources, instanceInfo);
    return fighter;
}
