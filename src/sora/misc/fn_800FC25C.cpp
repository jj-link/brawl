#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_800FC300();

extern "C" void fn_800FC25C() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x68, 0x28);
    if (obj != 0) {
        fn_800FC300();
    }
}
