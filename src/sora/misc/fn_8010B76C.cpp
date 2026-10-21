#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_8010B7A0();

extern "C" void fn_8010B76C() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x364, 0x28);
    if (obj != 0) {
        fn_8010B7A0();
    }
}
