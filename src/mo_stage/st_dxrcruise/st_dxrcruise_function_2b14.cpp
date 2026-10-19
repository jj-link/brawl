#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_80_A4();

extern "C" {
void fn_80_2B14() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1014, 0xf);
    if (p != 0) {
        fn_80_A4();
    }
}
}
