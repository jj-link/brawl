#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_67F0[];
extern "C" unsigned char lbl_1_data_6B34[];

extern "C" void* fn_1_20D90() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x14, 0x2E);
    if (obj) {
        *(void**)obj = lbl_1_data_67F0;
        *((void**)obj + 1) = lbl_1_data_6B34;
    }
    return obj;
}
