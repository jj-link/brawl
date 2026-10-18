#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_10_60();
extern "C" void fn_10_5F0(void*, void*);

extern "C" void* fn_10_0(void* arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x654, 0x2a);
    if (obj) {
        obj = fn_10_60();
    }
    fn_10_5F0(obj, arg);
    return obj;
}
