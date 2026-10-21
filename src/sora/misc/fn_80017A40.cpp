#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_80017A84(void* obj, void* arg);

extern "C" void fn_80017A40(void* arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x90, 0x2);
    if (obj != 0) {
        fn_80017A84(obj, arg);
    }
}
