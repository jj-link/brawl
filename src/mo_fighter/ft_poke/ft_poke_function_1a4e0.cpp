#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_116_13DCC(void*, void*, int, void*, void*);
}

extern "C" void* fn_116_1A4E0(void* arg0, void* arg1, int arg2,
                               void* arg3, void* arg4) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x16328, arg2);
    if (obj)
        obj = fn_116_13DCC(obj, arg1, arg2, arg3, arg4);
    return obj;
}
