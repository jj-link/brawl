#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_85E8[];
extern "C" char lbl_1_data_8670[];

extern "C" {
void* fn_1_342BC() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x20, 0x2E);
    if (p != 0) {
        unsigned long* w = (unsigned long*)p;
        w[0] = (unsigned long)lbl_1_data_85E8;
        w[1] = (unsigned long)lbl_1_data_8670;
        w[2] = 0;
        w[7] = 0;
    }
    return p;
}
}
