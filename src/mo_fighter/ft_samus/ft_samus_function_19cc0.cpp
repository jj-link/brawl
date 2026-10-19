#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_94_11C78(void*, int, int, int, int);
}

extern "C" void fn_94_19CC0(int a0, int a1, int a2, int a3, int a4) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x19CB0, a2);
    if (obj) {
        fn_94_11C78(obj, a1, a2, a3, a4);
    }
}
