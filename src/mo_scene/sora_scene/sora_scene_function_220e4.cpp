#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_6D68[];
extern "C" char lbl_1_data_6EF0[];

extern "C" void* fn_1_220E4() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x20, 0x2E);
    if (obj != 0) {
        *(void**)obj = lbl_1_data_6D68;
        *(void**)((char*)obj + 4) = lbl_1_data_6EF0;
        *(unsigned int*)((char*)obj + 8) = 2;
    }
    return obj;
}
