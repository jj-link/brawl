#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_87B0[];
extern "C" unsigned char lbl_1_data_8834[];

extern "C" void* fn_1_351CC() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x20, 0x2e);
    if (p) {
        *(void**)p = lbl_1_data_87B0;
        *(void**)((char*)p + 4) = lbl_1_data_8834;
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 0x1c) = 0;
    }
    return p;
}
