#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_9150[];
extern "C" unsigned char lbl_1_data_9190[];

extern "C" void* fn_1_3A360() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x14, 0x2E);
    if (obj != 0) {
        *(void**)obj = lbl_1_data_9150;
        *(void**)((char*)obj + 4) = lbl_1_data_9190;
        *(int*)((char*)obj + 8) = 0;
    }
    return obj;
}
