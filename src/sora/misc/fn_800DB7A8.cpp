#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_800DB83C();

extern "C" void fn_800DB7A8() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xC8, 0x2);
    if (obj != 0) {
        fn_800DB83C();
    }
}
