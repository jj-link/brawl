#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_15_60();
extern "C" void fn_15_6AC(void*, void*);

extern "C" void* fn_15_0(void* arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xD78, 0x2A);
    if (obj) {
        obj = fn_15_60();
    }
    fn_15_6AC(obj, arg);
    return obj;
}
