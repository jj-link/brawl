#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_124_70(void* p, int a, int b, int c, int d);

extern "C" void fn_124_B2A4(int unused, int a, int b, int c, int d)
{
    void* p = __nw__FUlQ25Heaps8HeapType(0x9A5C, b);
    if (p != 0) {
        fn_124_70(p, a, b, c, d);
    }
}
