#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_52_A4(void* self);

extern "C" void fn_52_70() {
    void* ptr = __nw__FUlQ25Heaps8HeapType(0x60C, 0xF);
    if (ptr) {
        fn_52_A4(ptr);
    }
}
