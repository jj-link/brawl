#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_50_A4();

extern "C" void fn_50_70() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x424, 0x0F);
    if (obj != 0) {
        fn_50_A4();
    }
}
