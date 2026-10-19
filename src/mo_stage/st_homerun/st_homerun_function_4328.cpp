#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_88_A4(void*);

extern "C" void fn_88_4328() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x810, 0xF);
    if (obj != 0) {
        fn_88_A4(obj);
    }
}
