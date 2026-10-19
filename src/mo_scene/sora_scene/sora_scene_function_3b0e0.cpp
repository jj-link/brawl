#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_9728[];
extern "C" unsigned char lbl_1_data_9790[];

extern "C" void* fn_1_3B0E0() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x14, 0x2e);
    if (p != 0) {
        *(void**)p = lbl_1_data_9728;
        *(void**)((char*)p + 4) = lbl_1_data_9790;
        *(int*)((char*)p + 8) = 0;
    }
    return p;
}
