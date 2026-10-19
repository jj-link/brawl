#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8A18[];
extern "C" unsigned char lbl_1_data_8A74[];

extern "C" void* fn_1_36934() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x14, 0x2E);
    if (obj) {
        *(void**)obj = lbl_1_data_8A18;
        *(void**)((char*)obj + 4) = lbl_1_data_8A74;
        *(int*)((char*)obj + 8) = 0;
    }
    return obj;
}
