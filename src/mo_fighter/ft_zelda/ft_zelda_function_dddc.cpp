#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_104_70(void*, void*, int, void*, void*);
}

extern "C" void fn_104_DDDC(void*, void* a, int heap, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x18678, heap);
    if (obj != 0) {
        fn_104_70(obj, a, heap, b, c);
    }
}
