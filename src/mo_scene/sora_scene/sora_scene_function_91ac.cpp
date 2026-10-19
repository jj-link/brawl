#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_2160[];
extern "C" unsigned char lbl_1_data_21C8[];

extern "C" void* fn_1_91AC() {
    void** obj = (void**)__nw__FUlQ25Heaps8HeapType(0xC, 0x2E);
    if (obj != 0) {
        obj[0] = lbl_1_data_2160;
        obj[1] = lbl_1_data_21C8;
    }
    return obj;
}
