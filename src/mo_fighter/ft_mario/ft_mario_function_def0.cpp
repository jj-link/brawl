#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_91_70(void*, int, int, int, int);

void fn_91_DEF0(int unused, int a, int heap, int c, int d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x2DBE8, heap);
    if (obj != 0) {
        fn_91_70(obj, a, heap, c, d);
    }
}
}
