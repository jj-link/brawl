#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" const char lbl_1_data_3B78[];
extern "C" unsigned char lbl_1_data_3BF8[];

extern "C" void* fn_1_AE80() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xC, 0x2E);
    if (obj != 0) {
        *(const char**)obj = lbl_1_data_3B78;
        *(const void**)((char*)obj + 4) = lbl_1_data_3BF8;
    }
    return obj;
}
