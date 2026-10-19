#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_92_70(void*, void*, int, void*, void*);
}

extern "C" void fn_92_CA04(void*, void* a, int heap, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1259c, heap);
    if (obj) {
        fn_92_70(obj, a, heap, b, c);
    }
}
