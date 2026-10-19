#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_97_70(void*, void*, int, void*, void*);
}

extern "C" void* fn_97_E8BC(void* unused, void* a, int b, void* c, void* d) {
    void* result = __nw__FUlQ25Heaps8HeapType(0x1CD98, b);
    if (result)
        result = fn_97_70(result, a, b, c, d);
    return result;
}
