#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_9068[];
extern "C" unsigned char lbl_1_data_90E8[];

extern "C" void* fn_1_3971C() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x20, 0x2E);
    if (obj) {
        *(void**)obj = lbl_1_data_9068;
        *(void**)((char*)obj + 4) = lbl_1_data_90E8;
        *(int*)((char*)obj + 8) = 0;
    }
    return obj;
}
