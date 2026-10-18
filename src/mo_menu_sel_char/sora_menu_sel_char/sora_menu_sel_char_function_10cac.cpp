#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_10_10D0C();
extern "C" void fn_10_11100(void*, void*);

extern "C" void* fn_10_10CAC(void* arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x448, 0x2a);
    if (obj != 0)
        obj = fn_10_10D0C();
    fn_10_11100(obj, arg);
    return obj;
}
