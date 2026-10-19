#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_102_F4C4(void*, void*, int, void*, void*);
}

extern "C" void* fn_102_14F74(void*, void* arg1, int heap, void* arg3, void* arg4) {
    void* result = __nw__FUlQ25Heaps8HeapType(0x13F24, heap);
    if (result)
        result = fn_102_F4C4(result, arg1, heap, arg3, arg4);
    return result;
}
