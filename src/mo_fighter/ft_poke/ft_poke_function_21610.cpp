#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_116_1B63C(void*, void*, int, void*, void*);
}

extern "C" void fn_116_21610(void*, void* a, int b, void* c, void* d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1116c, b);
    if (obj)
        fn_116_1B63C(obj, a, b, c, d);
}
