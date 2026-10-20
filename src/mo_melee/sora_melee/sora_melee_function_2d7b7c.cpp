#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_27CEF0();
extern "C" char lbl_27_data_7B7C8[];

extern "C" void* fn_27_2D7B7C() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x3c, 0xf);
    if (p != 0) {
        fn_27_27CEF0();
        *(void**)p = lbl_27_data_7B7C8;
    }
    return p;
}
