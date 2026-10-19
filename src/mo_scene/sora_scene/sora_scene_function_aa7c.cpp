#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_3A98[];
extern "C" char lbl_1_data_3B18[];

extern "C" void fn_1_AA7C() {
    void** obj = (void**)__nw__FUlQ25Heaps8HeapType(0xc, 0x2e);
    if (obj != 0) {
        obj[0] = lbl_1_data_3A98;
        obj[1] = lbl_1_data_3B18;
    }
}
