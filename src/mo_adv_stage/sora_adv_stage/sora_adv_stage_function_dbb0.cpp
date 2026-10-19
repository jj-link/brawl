#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_40_A4(void*);

extern "C" void fn_40_DBB0() {
    void* object = __nw__FUlQ25Heaps8HeapType(0x630, 0x0f);
    if (object) {
        fn_40_A4(object);
    }
}
