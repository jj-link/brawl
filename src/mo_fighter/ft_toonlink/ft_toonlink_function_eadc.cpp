#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_121_70(void*, void*, int, void*, void*);
}

extern "C" void fn_121_EADC(void*, void* a, int heap, void* c, void* d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1A39C, heap);
    if (obj)
        fn_121_70(obj, a, heap, c, d);
}
