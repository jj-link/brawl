#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_125_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_125_E7D4(void* a, void* b, int heap, void* c, void* d) {
    void* fighter = __nw__FUlQ25Heaps8HeapType(0x1CCDCU, heap);
    if (fighter)
        fighter = fn_125_70(fighter, b, heap, c, d);
    return fighter;
}
