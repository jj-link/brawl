#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_8009ED40(void*, int, int);

extern "C" void fn_8009F474(int a, int b, int c) {
    void* ptr = __nw__FUlQ25Heaps8HeapType(0x84, a);
    if (ptr) {
        fn_8009ED40(ptr, b, c);
    }
}
