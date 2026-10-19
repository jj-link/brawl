#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern char lbl_1_data_0[];
extern char lbl_1_data_58[];

extern "C" void fn_1_40C() {
    void** p = (void**)__nw__FUlQ25Heaps8HeapType(0x18, 0x2E);
    if (p) {
        p[0] = lbl_1_data_0;
        p[1] = lbl_1_data_58;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
    }
}
