#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_86D0[];
extern "C" unsigned char lbl_1_data_8750[];

extern "C" void* fn_1_349B4() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x24, 0x2e);
    if (p != 0) {
        *(void**)p = lbl_1_data_86D0;
        *((void**)p + 1) = lbl_1_data_8750;
        *((unsigned long*)p + 2) = 0;
    }
    return p;
}
