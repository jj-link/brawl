#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_16B8[];
extern "C" unsigned char lbl_1_data_1740[];

extern "C" void* fn_1_6B08() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xC, 0x2E);
    if (obj) {
        *(void**)obj = lbl_1_data_16B8;
        *(void**)((char*)obj + 4) = lbl_1_data_1740;
        *(int*)((char*)obj + 8) = 0;
    }
    return obj;
}
