#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8890[];
extern "C" unsigned char lbl_1_data_8924[];

extern "C" void* fn_1_35F14() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x14, 0x2e);
    if (p) {
        *(void**)p = lbl_1_data_8890;
        *((void**)p + 1) = lbl_1_data_8924;
        *((unsigned int*)p + 2) = 0;
    }
    return p;
}
