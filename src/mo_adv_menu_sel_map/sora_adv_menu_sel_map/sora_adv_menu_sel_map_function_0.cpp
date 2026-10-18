#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_31_60();
extern "C" void fn_31_534(void*, void*);

extern "C" void* fn_31_0(void* arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x5ec, 0x2a);
    if (obj != 0)
        obj = fn_31_60();
    fn_31_534(obj, arg);
    return obj;
}
