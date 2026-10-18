#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_5D08[];
extern "C" char lbl_1_data_5D18[];

extern "C" void* fn_1_1BCB4() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x18, 0x2e);
    if (p) {
        unsigned int* words = (unsigned int*)p;
        words[0] = (unsigned int)lbl_1_data_5D08;
        words[1] = (unsigned int)lbl_1_data_5D18;
        words[2] = 0;
        words[3] = 4;
        words[4] = 0;
        words[5] = 0;
    }
    return p;
}
