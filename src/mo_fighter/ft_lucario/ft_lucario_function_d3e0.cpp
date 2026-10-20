#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_118_70(void*, void*, int, void*, void*);

extern "C" void fn_118_D3E0(void* unused, void* a1, int heapType, void* a3, void* a4) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x10548, heapType);
    if (obj != 0) {
        fn_118_70(obj, a1, heapType, a3, a4);
    }
}
