#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_6CA0[];
extern "C" unsigned char lbl_1_data_6D08[];

extern "C" void* fn_1_21E90() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x18, 0x2E);
    if (obj != 0) {
        *(void**)obj = lbl_1_data_6CA0;
        *((void**)obj + 1) = lbl_1_data_6D08;
        *((unsigned int*)obj + 2) = 0;
    }
    return obj;
}
