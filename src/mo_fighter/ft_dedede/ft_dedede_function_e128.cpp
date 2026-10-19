#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_117_70(void* work, int a2, int a3, int a4, int a5);

extern "C" void fn_117_E128(void* work, int a2, int a3, int a4, int a5) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x4777c, a3);
    if (obj != 0) {
        fn_117_70(obj, a2, a3, a4, a5);
    }
}
