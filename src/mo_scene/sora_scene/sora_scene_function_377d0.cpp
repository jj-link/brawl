#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8C28[];
extern "C" unsigned char lbl_1_data_8D40[];

extern "C" void* fn_1_377D0() {
    unsigned int* obj = (unsigned int*)__nw__FUlQ25Heaps8HeapType(0x18, 0x2E);
    if (obj != 0) {
        obj[0] = (unsigned int)lbl_1_data_8C28;
        obj[1] = (unsigned int)lbl_1_data_8D40;
        obj[2] = 0;
    }
    return obj;
}
