#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_14_60();
extern "C" void fn_14_3F8(void*, void*);

extern "C" void* fn_14_0(void* arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x2ac8, 0x2a);
    if (obj) {
        obj = fn_14_60();
    }
    fn_14_3F8(obj, arg);
    return obj;
}
