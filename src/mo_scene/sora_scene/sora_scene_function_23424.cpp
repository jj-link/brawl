#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_7064[];
extern "C" char lbl_1_data_7114[];

extern "C" void* fn_1_23424() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x14, 0x2e);
    if (p) {
        *(void**)p = lbl_1_data_7064;
        *(void**)((char*)p + 4) = lbl_1_data_7114;
        *(int*)((char*)p + 8) = 0;
    }
    return p;
}
