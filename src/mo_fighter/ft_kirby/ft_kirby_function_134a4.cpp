#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_96_70(void*, int, int, int, int);
}

extern "C" void fn_96_134A4(void* unused, int a, int heap, int c, int d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1C294, heap);
    if (obj) {
        fn_96_70(obj, a, heap, c, d);
    }
}
