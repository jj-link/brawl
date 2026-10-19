#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_122_70(void*, void*, int, void*, void*);
}

extern "C" void fn_122_13CB8(void*, void* a, int heap, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x2D040, heap);
    if (obj) {
        fn_122_70(obj, a, heap, b, c);
    }
}
